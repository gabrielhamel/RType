/**
 * @file World.cpp
 * @author Gabriel Hamel (gabriel.hamel@epitech.eu)
 * @brief Implementation of World.hpp
 * @version 1.0
 * @date 2019-11-07
 *
 * @copyright Copyright (c) 2019
 *
 */

#include <algorithm>
#include "World.hpp"
#include "GameSystems.hpp"

using namespace rt::engine;

World::World(WorldHandler &handler) :
_handler(handler)
{

}

World::~World(void)
{
    _entity.clear();
    _entityKilled.clear();
}

Entity &World::createEntity(std::vector<std::reference_wrapper<rt::network::BoostUdpEndpoint>> endpoint)
{
    _entity.push_back(std::make_unique<Entity>(*this, endpoint));
    _handler.onEntityCreated(*_entity.back());
    return *_entity.back();
}

Entity &World::createEntity(const std::string &id, std::vector<std::reference_wrapper<rt::network::BoostUdpEndpoint>> endpoints)
{
    _entity.push_back(std::make_unique<Entity>(*this, id, endpoints));
    _handler.onEntityCreated(*_entity.back());
    return *_entity.back();
}

std::vector<std::unique_ptr<Entity>>::iterator World::findEntity(std::vector<std::unique_ptr<Entity>> &list, const Entity &entity)
{
    auto it = std::find_if(list.begin(), list.end(), [&](const std::unique_ptr<Entity> &ptr) {
        return *ptr.get() == entity;
    });
    return it;
}

void World::killEntity(Entity &entity)
{
    auto entityIt = findEntity(_entity, entity);
    if (entityIt == _entity.end())
        return;
    _handler.onEntityKilled(entity);
    _entityKilled.push_back(std::move(*entityIt));
    _entity.erase(entityIt);
    if (entity.isKilled() == false)
        entity.kill();
}

std::unordered_map<SystemType, std::shared_ptr<System>> World::getSystems(void)
{
    return _systems;
}

void World::refresh(void)
{
    _entityKilled.clear();
}

WorldHandler &World::getHandler()
{
    return _handler;
}

Entity &World::getEntity(const std::string id)
{
    auto it = std::find_if(_entity.begin(), _entity.end(), [&](const std::unique_ptr<Entity> &ptr) {
        return ptr.get()->id.to_string() == id;
    });
    if (it != _entity.end())
        return *it->get();
    auto entity = Entity(*this);
    return entity;
}

Entity &World::getEntity(const std::string id, rt::network::BoostUdpEndpoint &endpoint)
{
    auto it = std::find_if(_entity.begin(), _entity.end(), [&](const std::unique_ptr<Entity> &ptr) {
        return ptr.get()->id.to_string() == id;
    });
    if (it != _entity.end())
        return *it->get();
    auto &entity = createEntity(id, std::vector<std::reference_wrapper<rt::network::BoostUdpEndpoint>>({endpoint}));
    entity.activate(); // Pas ouf
    return entity;
}

System &World::addSystem(SystemType system)
{
    if (hasSystem(system))
        throw std::runtime_error("This system is already assigned to that world");
    _systems.emplace(system, rt::game::systems::createSystems(system));
    _handler.onSystemAdded(system);
    return *_systems[system];
}

void World::removeSystem(SystemType system)
{
    auto it = _systems.find(system);
    if (it == _systems.end())
        throw std::runtime_error("There is not that system in that world");
    _handler.onSystemRemoved(system);
    _systems.erase(it);
}

bool World::hasSystem(SystemType system)
{
    return _systems.find(system) != _systems.end();
}

System &World::getSystem(SystemType system)
{
    auto it = _systems.find(system);
    if (it == _systems.end())
        throw std::runtime_error("There is not that system in that world");
    return *it->second;
}

std::vector<std::reference_wrapper<Entity>> World::getEntities(void)
{
    std::vector<std::reference_wrapper<Entity>> res;
    for (auto &entity : _entity)
        res.push_back(*entity);
    return res;
}
