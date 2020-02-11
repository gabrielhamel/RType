/**
 * @file System.hpp
 * @author Gabriel Hamel (gabriel.hamel@epitech.eu)
 * @brief
 * @version 1.0
 * @date 2019-11-07
 *
 * @copyright Copyright (c) 2019
 *
 */

#pragma once

#include "ASystem.hpp"
#include "SystemType.hpp"

namespace rt::engine
{
    /**
     * @brief Command entity
     *
     */
    class System : public ASystem
    {
        public:
            System(SystemType type, ComponentList requires = ComponentList(), ComponentList excludes = ComponentList()) : ASystem(type, requires, excludes) {}
            /**
             * @brief Destroy the System object
             *
             */
            virtual ~System(void) {};
    };

    template <class T>
    SystemType getSystemType(void)
    {
        return ClassSystemType<System>::getType<T>();
    }

}
