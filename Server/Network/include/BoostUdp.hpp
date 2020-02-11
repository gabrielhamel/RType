/**
 * @file BoostUdp.hpp
 * @author Gabriel Hamel (gabriel.hamel@epitech.eu)
 * @brief Boost udp implementation
 * @version 1.0
 * @date 2019-11-29
 *
 * @copyright Copyright (c) 2019
 *
 */

#pragma once

#include <boost/asio.hpp>
#include <boost/asio/ip/udp.hpp>
#include "Byte.hpp"

namespace rt::network
{
    /**
     * @brief Implementation of udp client in boost
     *
     */
    class BoostUdpEndpoint
    {
        private:
            /**
             * @brief My ip
             *
             */
            uint32_t _myIp;
            /**
             * @brief My port
             *
             */
            uint16_t _myPort;
            /**
             * @brief The boost endpoint
             *
             */
            boost::asio::ip::udp::endpoint _target;
            /**
             * @brief My endpoint
             *
             */
            boost::asio::ip::udp::endpoint _me;
            /**
             * @brief The IO
             *
             */
            boost::asio::io_service _service;
            /**
             * @brief The socket
             *
             */
            boost::asio::ip::udp::socket _socket;
        public:
            /**
             * @brief Construct a new Boost Udp Endpoint object
             * @param ip
             * @param port
             * @param ip
             * @param port
             *
             */
            BoostUdpEndpoint(const std::string &targetIp, uint16_t targetPort, const std::string &myIp, uint16_t myPort);
            /**
             * @brief Construct Boost Udp Endpoint
             *
             * @param ip
             * @param port
             * @param ip
             * @param port
             */
            BoostUdpEndpoint(uint32_t targetIp, uint16_t targetPort, uint32_t myIp, uint16_t myPort);
            /**
             * @brief Destroy the Boost Udp Endpoint object
             *
             */
            ~BoostUdpEndpoint(void);
            /**
             * @brief Return port
             *
             * @return uint16_t
             */
            uint16_t targetPort(void) const;
            /**
             * @brief Return ip
             *
             * @return uint32_t
             */
            uint32_t targetIp(void) const;
            /**
             * @brief Return port
             *
             * @return uint16_t
             */
            uint16_t myPort(void) const;
            /**
             * @brief Return ip
             *
             * @return uint32_t
             */
            uint32_t myIp(void) const;
            /**
             * @brief Send Byte frame
             *
             * @param packet
             */
            void send(rt::Byte packet);
    };

}
