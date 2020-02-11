/**
 * @file BoostServer.hpp
 * @author Gabriel Hamel (gabriel.hamel@epitech.eu)
 * @brief The famous server
 * @version 1.0
 * @date 2019-11-29
 *
 * @copyright Copyright (c) 2019
 *
 */

#pragma once

#include <vector>
#include <boost/function.hpp>
#include <boost/bind.hpp>
#include "BoostUdp.hpp"

namespace rt::network
{
    /**
     * @brief The class who store clients and read from there
     *
     */
    class BoostServer
    {
        public:
            /**
             * @brief The special data passed to rcvHandler
             *
             */
            void *data;
            /**
             * @brief THe functor
             *
             */
            typedef boost::function<void (rt::network::BoostUdpEndpoint &, rt::Byte, void *)> RcvFptr;
        private:
            /**
             * @brief My stored ip
             *
             */
            uint32_t _myIp;
            /**
             * @brief THe function overrided when rcv packet
             *
             */
            RcvFptr _onRcv;
            /**
             * @brief The read buffer
             *
             */
            std::array<uint8_t, 4096> _buffer;
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
            /**
             * @brief handle recv
             *
             * @param packet
             */
            void recvPacket(const boost::system::error_code &error, std::size_t size);
            /**
             * @brief Set boost to read
             *
             */
            void prepareRead(void);
        public:
            /**
             * @brief Construct Boost Server
             *
             */
            BoostServer(const std::string &myIp, uint16_t myPort, RcvFptr rcvHandler);
            /**
             * @brief Construct Boost Server
             *
             * @param myIp
             * @param myPort
             * @param rcvHandler
             */
            BoostServer(uint32_t myIp, uint16_t myPort, RcvFptr rcvHandler);
            /**
             * @brief Construct Boost Server
             *
             */
            virtual ~BoostServer(void);
            /**
             * @brief Launch the server in infinite loop
             *
             */
            void run(void);
            /**
             * @brief Shutdown the server
             *
             */
            void stop(void);
            /**
             * @brief Function to launch by a thread. "server" is this class
             *
             * @param server
             */
            static void threadLaunch(void *server);
            /**
             * @brief Get All Clients
             *
             * @return std::vector<std::reference_wrapper<BoostUdpEndpoint>>
             */
            std::vector<std::reference_wrapper<BoostUdpEndpoint>> getAllClients(void) const;
            /**
             * @brief Send a packet to all client
             *
             * @param packet
             */
            void broadcast(rt::Byte packet);
        protected:
            /**
             * @brief All clients
             *
             */
            std::unordered_map<uint64_t, std::unique_ptr<BoostUdpEndpoint>> _clients;
    };

}
