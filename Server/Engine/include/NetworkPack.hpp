/**
 * @file NetworkPack.hpp
 * @author Gabriel Hamel (gabriel.hamel@epitech.eu)
 * @brief
 * @version 1.0
 * @date 2019-11-30
 *
 * @copyright Copyright (c) 2019
 *
 */

#pragma once

#include "Byte.hpp"

namespace rt::engine
{
    class Entity;
}

namespace rt::network
{
    /**
     * @brief To get the component has network frame
     *
     * @param component
     * @return Byte
     */
    rt::Byte pack(rt::engine::Entity &entity, rt::engine::ComponentType component);
    /**
     * @brief Get entity to a network frame
     *
     * @param entity
     * @return rt::Byte
     */
    rt::Byte pack(rt::engine::Entity &entity);
}
