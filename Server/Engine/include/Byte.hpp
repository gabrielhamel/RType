/**
 * @file Byte.hpp
 * @author Gabriel Hamel (gabriel.hamel@epitech.eu)
 * @brief Class to store data
 * @version 1.0
 * @date 2019-11-27
 *
 * @copyright Copyright (c) 2019
 *
 */

#pragma once

#include <cstdint>
#include <string>
#include <vector>

namespace rt
{
    /**
     * @brief Class container with serialization and deserialization
     *
     */
    class Byte
    {
        private:
            /**
             * @brief Data stored
             *
             */
            std::vector<uint8_t> _data;
        public:
            /**
             * @brief Construct a new Byte object
             *
             */
            Byte();
            /**
             * @brief Destroy the Byte object
             *
             */
            ~Byte();
            /**
             * @brief Construct a new Byte object by copy
             *
             * @param copy
             */
            Byte(const Byte &copy);
            /**
             * @brief + override
             *
             * @param packet
             * @return Byte&
             */
            Byte &operator+=(const Byte &packet);
            /**
             * @brief Overload = operator
             *
             * @param copy
             * @return Byte&
             */
            Byte &operator=(const Byte &copy);
            /**
             * @brief To store an int
             *
             * @param data
             * @return Byte&
             */
            Byte &operator<<(int data);
            /**
             * @brief To store an size_t
             *
             * @param data
             * @return Byte&
             */
            Byte &operator<<(const std::string &data);
            /**
             * @brief To store an uint8_t
             *
             * @param data
             * @return Byte&
             */
            Byte &operator<<(uint8_t data);
            /**
             * @brief To store an uint16_t
             *
             * @param data
             * @return Byte&
             */
            Byte &operator<<(uint16_t data);
            /**
             * @brief To store an uint32_t
             *
             * @param data
             * @return Byte&
             */
            Byte &operator<<(uint32_t data);
            /**
             * @brief To store an uint64_t
             *
             * @param data
             * @return Byte&
             */
            Byte &operator<<(uint64_t data);
            /**
             * @brief To store an float
             *
             * @param data
             * @return Byte&
             */
            Byte &operator<<(float data);
            /**
             * @brief Deserialize an int
             *
             * @return int
             */
            operator int();
            /**
             * @brief Deserialize an std::string
             *
             * @return std::string
             */
            operator std::string();
            /**
             * @brief Deserialize an uint8_t
             *
             * @return uint8_t
             */
            operator uint8_t();
            /**
             * @brief Deserialize an uint16_t
             *
             * @return uint16_t
             */
            operator uint16_t();
            /**
             * @brief Deserialize an uint32_t
             *
             * @return uint32_t
             */
            operator uint32_t();
            /**
             * @brief Deserialize an uint64_t
             *
             * @return uint64_t
             */
            operator uint64_t();
            /**
             * @brief Get an float
             *
             * @return float
             */
            operator float();
            /**
             * @brief Get all data stored
             *
             * @return std::vector<uint8_t>
             */
            std::vector<uint8_t> getData(void) const;
    };

}
