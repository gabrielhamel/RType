/**
 * @file Component.hpp
 * @author Gabriel Hamel (gabriel.hamel@epitech.eu)
 * @brief
 * @version 1.0
 * @date 2019-11-09
 *
 * @copyright Copyright (c) 2019
 *
 */

#pragma once

#include "NonCopyable.hpp"
#include "ComponentType.hpp"
#include "Serializable.hpp"

namespace rt::engine
{
    /**
     * @brief Component is a part of entity like positon, speed ...
     *
     */
    class Component : public NonCopyable, public Serializable
    {
        public:
            /**
             * @brief Destroy the Component object
             *
             */
            virtual ~Component(void) {}
    };

    template <class T>
    ComponentType getComponentType(void)
    {
        return ClassComponentType<Component>::getType<T>();
    }

}
