/**
 * @file CoreHandler.hpp
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
#include "GameComponents.hpp"
#include "BoostUdp.hpp"

using namespace rt::engine;

namespace rt::core
{

    class Core;

    class CoreHandler : public rt::engine::WorldHandler
    {
        private:
            Core &_core;
        public:
            CoreHandler(Core &core);
            virtual ~CoreHandler(void);

            virtual void onEntityCreated(Entity &entity);
            virtual void onEntityKilled(Entity &entity);

            virtual void onSystemAdded(SystemType system);
            virtual void onSystemRemoved(SystemType system);

            virtual void onEntityActivated(Entity &entity);
            virtual void onEntityDesactivated(Entity &entity);

            virtual void onEntityComponentAdded(Entity &entity, ComponentType component);
            virtual void onEntityComponentUpdated(Entity &entity, ComponentType component);
            virtual void onEntityComponentRemoved(Entity &entity, ComponentType component);

            virtual void onSystemEntityAdded(Entity &entity, SystemType system);
            virtual void onSystemEntityRemoved(Entity &entity, SystemType system);

            virtual std::vector<std::reference_wrapper<rt::network::BoostUdpEndpoint>> getAllConnections();
    };

}
