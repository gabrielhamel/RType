/**
 * @file EngineCli.hpp
 * @author Gabriel Hamel (gabriel.hamel@epitech.ey)
 * @brief Implementation of AEngineCli
 * @version 1.0
 * @date 2019-11-20
 *
 * @copyright Copyright (c) 2019
 *
 */

#pragma once

#include "AEngine.hpp"
#include "CoreHandler.hpp"
#include "GameComponents.hpp"
#include "GameSystems.hpp"
#include "World.hpp"
#include "Player.hpp"

namespace rt::core
{
    class Core;
}

namespace rt::game::client
{
    class EngineCli : public rt::game::client::AEngine, public rt::core::CoreHandler
    {
        private:
            unsigned int _framerate;
            rt::core::Core &_core;
            rt::engine::World &_world;
            bool _noPlayerBind;
            void bindPlayer(Entity &entity);
            std::string _me;
        public:
            EngineCli(rt::core::Core &core);
            ~EngineCli();
            bool onEventTrigger(sf::Event &event);
            void draw(sf::RenderWindow &window);
            void update(float ellapsedTime);
            void onEntityComponentAdded(Entity &entity, ComponentType component);
            void onEntityComponentUpdated(Entity &entity, ComponentType component);
    };

}
