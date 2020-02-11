/**
 * @file GameHandler.hpp
 * @author Gabriel Hamel (gabriel.hamel@epitech.eu)
 * @brief
 * @version 1.0
 * @date 2019-11-30
 *
 * @copyright Copyright (c) 2019
 *
 */

#pragma once

#include "WorldHandler.hpp"

using namespace rt::engine;

namespace rt::game
{
    class Game;

    class GameHandler : public rt::engine::WorldHandler
    {
        private:
            Game &_game;
        public:
            GameHandler(Game &game);
            ~GameHandler(void);

            void onEntityCreated(Entity &entity);
            void onEntityKilled(Entity &entity);

            void onSystemAdded(SystemType system);
            void onSystemRemoved(SystemType system);

            void onEntityActivated(Entity &entity);
            void onEntityDesactivated(Entity &entity);

            void onEntityComponentAdded(Entity &entity, ComponentType component);
            void onEntityComponentUpdated(Entity &entity, ComponentType component);
            void onEntityComponentRemoved(Entity &entity, ComponentType component);

            void onSystemEntityAdded(Entity &entity, SystemType system);
            void onSystemEntityRemoved(Entity &entity, SystemType system);

            std::vector<std::reference_wrapper<rt::network::BoostUdpEndpoint>> getAllConnections();
    };

}
