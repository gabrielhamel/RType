/**
 * @file GameServer.hpp
 * @author Gabriel Hamel (gabriel.hamel@epitech.eu)
 * @brief
 * @version 1.0
 * @date 2019-11-30
 *
 * @copyright Copyright (c) 2019
 *
 */

#pragma once

#include "BoostServer.hpp"

namespace rt::game
{
    class Game;

    class Server : public rt::network::BoostServer
    {
        public:
            Server(Game *game, const std::string &ip, uint16_t port);
            ~Server(void);
    };

}
