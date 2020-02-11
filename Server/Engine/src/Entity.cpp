/**
 * @file Entity.cpp
 * @author Gabriel Hamel
 * @brief Implementation of Entity.hpp
 * @version 1.0
 * @date 2019-11-07
 *
 * @copyright Copyright (c) 2019
 *
 */


#include "World.hpp"
#include "GameComponents.hpp"

using namespace rt::engine;

Entity::Entity(World &world) :
_world(world), _activated(false), _killed(false)
{

}

Entity::Entity(World &world, std::vector<std::reference_wrapper<rt::network::BoostUdpEndpoint>> endpoints) :
_endpoints(endpoints), _world(world), _activated(false), _killed(false)
{

}

Entity::Entity(World &world, const std::string &str, std::vector<std::reference_wrapper<rt::network::BoostUdpEndpoint>> endpoints) :
_endpoints(endpoints), _world(world), _activated(false), _killed(false)
{
    id.set(str);
}

Entity::~Entity(void)
{

}

bool Entity::operator==(const Entity &entity) const
{
    return entity.id == id && &entity._world == &_world;
}

World &Entity::getWorld(void) const
{
    return _world;
}

bool Entity::operator!=(const Entity &entity) const
{
    return !operator==(entity);
}

void Entity::activate(void)
{
    if (this->_killed) return;
    _activated = true;
    _world.getHandler().onEntityActivated(*this);
}

void Entity::desactivate(void)
{
    if (this->_killed) return;
    _activated = false;
    _world.getHandler().onEntityDesactivated(*this);
}

bool Entity::isActivated(void) const
{
    if (this->_killed) return false;
    return _activated;
}

void Entity::kill(void)
{
    auto systems = _world.getSystems();
    for (auto &system : systems)
        if (system.second->hasEntity(*this))
            system.second->removeEntity(*this);
    if (isActivated())
        desactivate();
    _killed = true;
    _world.killEntity(*this);
}

bool Entity::isKilled(void)
{
    if ((size_t)(void*)this == 0)
        return true;
    return _killed;
}

bool Entity::hasComponent(ComponentType component) const
{
    if (this->_killed) return false;
    return _components.find(component) != _components.end();
}

void Entity::onComponentAdded(ComponentType component)
{
    _world.getHandler().onEntityComponentAdded(*this, component);
}

void Entity::onComponentRemoved(ComponentType component)
{
    _world.getHandler().onEntityComponentRemoved(*this, component);
}

void Entity::onComponentUpdated(ComponentType component)
{
    _world.getHandler().onEntityComponentUpdated(*this, component);
}

Component &Entity::getComponent(ComponentType component) const
{
    auto it = _components.find(component);
    if (it == _components.end())
        throw std::runtime_error("There is not that component in that entity");
    return *it->second;
}

Component &Entity::addComponent(ComponentType component, rt::Byte packet)
{
    if (hasComponent(component))
        throw std::runtime_error("This component is already assigned to that entity");
    _components.emplace(component, rt::game::components::createComponent(component, packet));
    onComponentAdded(component);
    return getComponent(component);
}

void Entity::removeComponent(ComponentType component)
{
    if (this->_killed) return;
    auto it = _components.find(component);
    if (it == _components.end())
        throw std::runtime_error("There is not that component in that entity");
    onComponentRemoved(component);
    _components.erase(it);
}

void Entity::sendBroadcast(rt::Byte packet)
{
    auto con = _world.getHandler().getAllConnections();
    for (auto &cli : con)
        cli.get().send(packet);
}

void Entity::syncComponent(ComponentType component)
{
    if (this->_killed) return;
    auto it = _components.find(component);
    if (it == _components.end())
        throw std::runtime_error("There is not that component in that entity");
    rt::Byte cmd;
    cmd << rt::engine::TypeCmd::EntityComponentUpdated;
    rt::engine::ComponentType type = component;
    cmd += rt::network::pack(*this, type);
    sendBroadcast(cmd);
}

std::vector<ComponentType> Entity::getComponents(void) const
{
    std::vector<ComponentType> res;
    for (auto &i : _components) {
        res.push_back(i.first);
    }
    return res;
}
