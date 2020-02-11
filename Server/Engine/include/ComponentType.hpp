/**
 * @file ComponentType.hpp
 * @author Gabriel Hamel (gabriel.hamel@epitech.eu)
 * @brief The class that identify the component
 * @version 1.0
 * @date 2019-11-12
 *
 * @copyright Copyright (c) 2019
 *
 */

#pragma once

#include <cstddef>
#include <atomic>

namespace rt::engine
{
    typedef std::size_t ComponentType;

    template <typename TClass>
    class ClassComponentType
    {
        public:
            template <typename T>
            static ComponentType getType()
            {
                static const ComponentType id = _nextComponentType++;
                return id;
            }
        private:
            static std::atomic<ComponentType> _nextComponentType;
    };

    template <typename TClass>
    std::atomic<ComponentType> ClassComponentType<TClass>::_nextComponentType{0};

}
