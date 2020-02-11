/**
 * @file CoreHandler.cpp
 * @author Gabriel Hamel (gabriel.hamel@epitech.eu)
 * @brief
 * @version 1.0
 * @date 2019-11-30
 *
 * @copyright Copyright (c) 2019
 *
 */

#include "CoreHandler.hpp"
#include "Core.hpp"
#include "Texture.hpp"

using namespace rt::engine;
using namespace rt::core;

CoreHandler::CoreHandler(Core &core) :
_core(core)
{

}

CoreHandler::~CoreHandler(void)
{

}

void CoreHandler::onEntityCreated(Entity &entity)
{

}

void CoreHandler::onEntityKilled(Entity &entity)
{

}

void CoreHandler::onSystemAdded(SystemType system)
{

}

void CoreHandler::onSystemRemoved(SystemType system)
{

}

void CoreHandler::onEntityActivated(Entity &entity)
{

}

void CoreHandler::onEntityDesactivated(Entity &entity)
{

}

void CoreHandler::onEntityComponentAdded(Entity &entity, ComponentType component)
{

}

void CoreHandler::onEntityComponentUpdated(Entity &entity, ComponentType component)
{

}

void CoreHandler::onEntityComponentRemoved(Entity &entity, ComponentType component)
{

}

void CoreHandler::onSystemEntityAdded(Entity &entity, SystemType system)
{

}

void CoreHandler::onSystemEntityRemoved(Entity &entity, SystemType system)
{

}

std::vector<std::reference_wrapper<rt::network::BoostUdpEndpoint>> CoreHandler::getAllConnections()
{
    return { _core.getServer() };
}
