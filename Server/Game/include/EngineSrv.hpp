/**
 * @file EngineSrv.hpp
 * @author Gabriel Hamel (gabriel.hamel@epitech.ey)
 * @brief Implementation of AEngineSrv
 * @version 1.0
 * @date 2019-11-20
 *
 * @copyright Copyright (c) 2019
 *
 */

#pragma once

#include "Engine.hpp"
#include "GameComponents.hpp"
#include "GameSystems.hpp"
#include "WorldHandler.hpp"
#include "Enemy.hpp"

namespace rt::game
{
    class Game;
}

namespace rt::game::srv
{
    class EngineSrv : public rt::engine::WorldHandler
    {
        private:
            rt::game::Game &_game;
            rt::engine::World &_world;
            float _clockComponents;
            float _clockMonster;
        public:
            EngineSrv(rt::game::Game &game);
            ~EngineSrv(void);
            void update(float ellapsedTime);
            void onEntityCreated(rt::engine::Entity &entity);
            void onEntityKilled(rt::engine::Entity &entity);
            void onSystemAdded(rt::engine::SystemType system);
            void onSystemRemoved(rt::engine::SystemType system);
            void onEntityActivated(rt::engine::Entity &entity);
            void onEntityDesactivated(rt::engine::Entity &entity);
            void onEntityComponentAdded(rt::engine::Entity &entity, rt::engine::ComponentType component);
            void onEntityComponentUpdated(rt::engine::Entity &entity, rt::engine::ComponentType component);
            void onEntityComponentRemoved(rt::engine::Entity &entity, rt::engine::ComponentType component);
            void onSystemEntityAdded(rt::engine::Entity &entity, rt::engine::SystemType system);
            void onSystemEntityRemoved(rt::engine::Entity &entity, rt::engine::SystemType system);
            void onNewConnection(void);
            void addNewEnemy(rt::game::EnemyType enemy);
            void playerShoot(rt::engine::Entity &shooter);
            void enemyShoot(rt::engine::Entity &shooter);
            std::vector<std::reference_wrapper<rt::network::BoostUdpEndpoint>> getAllConnections();
    };

}
