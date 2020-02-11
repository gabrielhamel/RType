/**
 * @file WorldHandler.hpp
 * @author Gabriel Hamel (gabriel.hamel@epitech.eu)
 * @brief  Rip petit moteur partit trop tôt
 * @version 1.0
 * @date 2019-11-30
 *
 * @copyright Copyright (c) 2019
 *
 */

#pragma once

#include "Entity.hpp"
#include "System.hpp"
#include "BoostUdp.hpp"

namespace rt::engine
{
    /**
     * @brief Interface to override for world event
     *
     */
    class WorldHandler
    {
        public:
            virtual ~WorldHandler(void) = default;

            virtual void onEntityCreated(Entity &entity) = 0;
            virtual void onEntityKilled(Entity &entity) = 0;

            virtual void onSystemAdded(SystemType system) = 0;
            virtual void onSystemRemoved(SystemType system) = 0;

            virtual void onEntityActivated(Entity &entity) = 0;
            virtual void onEntityDesactivated(Entity &entity) = 0;

            virtual void onEntityComponentAdded(Entity &entity, ComponentType component) = 0;
            virtual void onEntityComponentUpdated(Entity &entity, ComponentType component) = 0;
            virtual void onEntityComponentRemoved(Entity &entity, ComponentType component) = 0;

            virtual void onSystemEntityAdded(Entity &entity, SystemType system) = 0;
            virtual void onSystemEntityRemoved(Entity &entity, SystemType system) = 0;

            virtual std::vector<std::reference_wrapper<rt::network::BoostUdpEndpoint>> getAllConnections() = 0;
    };

}
