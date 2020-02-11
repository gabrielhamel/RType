/**
 * @file GameHandler.cpp
 * @author Gabriel Hamel (gabriel.hamel@epitech.eu)
 * @brief
 * @version 1.0
 * @date 2019-11-30
 *
 * @copyright Copyright (c) 2019
 *
 */

#include "Game.hpp"
#include "NetworkPack.hpp"

using namespace rt::engine;
using namespace rt::game;

GameHandler::GameHandler(Game &game) :
_game(game)
{

}

GameHandler::~GameHandler(void)
{

}

void GameHandler::onEntityCreated(Entity &entity)
{

    Byte cmd;
    cmd << rt::engine::TypeCmd::EntityCreated;
    cmd += rt::network::pack(entity);
    _game.getServer().broadcast(cmd);

    _game.engineSrv.onEntityCreated(entity);
}

void GameHandler::onEntityKilled(Entity &entity)
{

    Byte cmd;
    cmd << rt::engine::TypeCmd::EntityKilled;
    cmd += rt::network::pack(entity);
    _game.getServer().broadcast(cmd);

    _game.engineSrv.onEntityKilled(entity);
}

void GameHandler::onEntityActivated(Entity &entity)
{

    Byte cmd;
    cmd << rt::engine::TypeCmd::EntityActivated;
    cmd += rt::network::pack(entity);
    _game.getServer().broadcast(cmd);

    _game.engineSrv.onEntityActivated(entity);
}

void GameHandler::onEntityDesactivated(Entity &entity)
{

    Byte cmd;
    cmd << rt::engine::TypeCmd::EntityDesactivated;
    cmd += rt::network::pack(entity);
    _game.getServer().broadcast(cmd);

    _game.engineSrv.onEntityDesactivated(entity);
}

void GameHandler::onEntityComponentAdded(Entity &entity, ComponentType component)
{

    Byte cmd;
    cmd << rt::engine::TypeCmd::EntityComponentCreated;
    cmd += rt::network::pack(entity, component);
    _game.getServer().broadcast(cmd);

    _game.engineSrv.onEntityComponentAdded(entity, component);
}

void GameHandler::onEntityComponentUpdated(Entity &entity, ComponentType component)
{

}

void GameHandler::onEntityComponentRemoved(Entity &entity, ComponentType component)
{

    Byte cmd;
    cmd << rt::engine::TypeCmd::EntityComponentRemoved;
    cmd += rt::network::pack(entity, component);
    _game.getServer().broadcast(cmd);

    _game.engineSrv.onEntityComponentRemoved(entity, component);
}

void GameHandler::onSystemAdded(SystemType system)
{

    Byte cmd;
    cmd << rt::engine::TypeCmd::SystemAdded;
    cmd << system;
    _game.getServer().broadcast(cmd);

    _game.engineSrv.onSystemAdded(system);
}

void GameHandler::onSystemRemoved(SystemType system)
{

    Byte cmd;
    cmd << rt::engine::TypeCmd::SystemRemoved;
    cmd << system;
    _game.getServer().broadcast(cmd);

    _game.engineSrv.onSystemRemoved(system);
}

void GameHandler::onSystemEntityAdded(Entity &entity, SystemType system)
{

    Byte cmd;
    cmd << rt::engine::TypeCmd::SystemEntityAdded;
    cmd << entity.id.to_string();
    cmd << system;
    _game.getServer().broadcast(cmd);

    _game.engineSrv.onSystemEntityAdded(entity, system);
}

void GameHandler::onSystemEntityRemoved(Entity &entity, SystemType system)
{

    Byte cmd;
    cmd << rt::engine::TypeCmd::SystemEntityRemoved;
    cmd << entity.id.to_string();
    cmd << system;
    _game.getServer().broadcast(cmd);

    _game.engineSrv.onSystemEntityRemoved(entity, system);
}

std::vector<std::reference_wrapper<rt::network::BoostUdpEndpoint>> GameHandler::getAllConnections()
{
    return _game.getServer().getAllClients();
}
