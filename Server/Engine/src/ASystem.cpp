/**
 * @file System.cpp
 * @author Gabriel Hamel (gabriel.hamel@epitech.eu)
 * @brief Implementation of System.hpp
 * @version 1.0
 * @date 2019-11-07
 *
 * @copyright Copyright (c) 2019
 *
 */

#include "ASystem.hpp"
#include "World.hpp"
#include "GameComponents.hpp"
#include "GameSystems.hpp"

using namespace rt::engine;

ASystem::ASystem(SystemType type, ComponentList requires, ComponentList excludes) :
_requires(requires), _excludes(excludes), _type(type)
{

}

ASystem::~ASystem(void)
{
    for (auto &it : _entities)
        it.release();
}

bool ASystem::isEntityApplicable(Entity &entity) const
{
    if (entity.isKilled() || !entity.isActivated())
        return false;
    for (auto &require : _requires) {
        if (!entity.hasComponent(require))
            return false;
    }
    for (auto &exclude : _excludes) {
        if (entity.hasComponent(exclude))
            return false;
    }
    return true;
}

std::vector<std::unique_ptr<Entity>>::const_iterator ASystem::findEntity(const Entity &entity) const
{
    std::vector<std::unique_ptr<Entity>>::const_iterator it = std::find_if(_entities.begin(), _entities.end(), [&](const std::unique_ptr<Entity> &ptr) {
        return *ptr.get() == entity;
    });
    return it;
}

void ASystem::addEntity(Entity &entity)
{
    if (entity.isKilled())
        return;
    std::vector<std::unique_ptr<Entity>>::iterator it = _entities.begin() + (findEntity(entity) - _entities.begin());
    if (it != _entities.end())
        throw std::runtime_error("This entity was already added");
    _entities.push_back(std::unique_ptr<Entity>(&entity));
    onEntityAdded(entity);
}

void ASystem::removeEntity(Entity &entity)
{
    std::vector<std::unique_ptr<Entity>>::iterator it = _entities.begin() + (findEntity(entity) - _entities.begin());
    if (it == _entities.end())
        return;
    *it->release();
    _entities.erase(it);
    onEntityRemoved(entity);
}

bool ASystem::hasEntity(Entity &entity) const
{
    return findEntity(entity) != _entities.end();
}

void ASystem::onEntityAdded(Entity &entity)
{
    entity.getWorld().getHandler().onSystemEntityAdded(entity, _type);
}

void ASystem::onEntityRemoved(Entity &entity)
{
    entity.getWorld().getHandler().onSystemEntityRemoved(entity, _type);
}

std::vector<std::reference_wrapper<Entity>> ASystem::getApplicableEntities(void) const
{
    std::vector<std::reference_wrapper<Entity>> res;

    for (auto &it : _entities)
        if (isEntityApplicable(*it))
            res.push_back(*it);
    return res;
}
