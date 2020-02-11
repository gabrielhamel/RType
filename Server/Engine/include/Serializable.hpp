
/**
 * @file Serializable.hpp
 * @author Gabriel Hamel (gabriel.hamel@epitech.eu)
 * @brief
 * @version 1.0
 * @date 2019-11-09
 *
 * @copyright Copyright (c) 2019
 *
 */

#pragma once

#include "Byte.hpp"

namespace rt
{

    class Serializable
    {
        public:
            /**
             * @brief Serialize data to Byte frame
             *
             * @return Byte
             */
            virtual Byte serialize(void) const = 0;
            /**
             * @brief Update from Byte frame
             *
             * @param packet
             */
            virtual void deserialize(Byte packet) = 0;
    };

}
