/**
 * @file Commands.hpp
 * @author Gabriel Hamel (gabriel.hamel@epitech.eu)
 * @brief
 * @version 1.0
 * @date 2019-11-30
 *
 * @copyright Copyright (c) 2019
 *
 */

#pragma once

namespace rt::engine
{

    enum TypeCmd {
        Connection,
        EntityCreated,
        EntityKilled,
        EntityActivated,
        EntityDesactivated,
        EntityComponentCreated,
        EntityComponentUpdated,
        EntityComponentRemoved,
        SystemAdded,
        SystemRemoved,
        SystemEntityAdded,
        SystemEntityRemoved
    };

}
