/**
 * @file SystemType.hpp
 * @author Gabriel Hamel (gabriel.hamel@epitech.eu)
 * @brief The class that identify the system
 * @version 1.0
 * @date 2019-11-20
 *
 * @copyright Copyright (c) 2019
 *
 */

#pragma once

#include <cstddef>
#include <atomic>

namespace rt::engine
{
    typedef std::size_t SystemType;

    template <typename TClass>
    class ClassSystemType
    {
        public:
            template <typename T>
            static SystemType getType()
            {
                static const SystemType id = _nextSystemType++;
                return id;
            }
        private:
            static std::atomic<SystemType> _nextSystemType;
    };

    template <typename TClass>
    std::atomic<SystemType> ClassSystemType<TClass>::_nextSystemType{0};

}
