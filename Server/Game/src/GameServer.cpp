/**
 * @file GameServer.cpp
 * @author Gabriel Hamel (gabriel.hamel@epitech.eu)
 * @brief
 * @version 1.0
 * @date 2019-11-30
 *
 * @copyright Copyright (c) 2019
 *
 */

#include "Game.hpp"

using namespace rt::game;

static void rcvHandler(rt::network::BoostUdpEndpoint &sender, rt::Byte packet, void *game)
{
    // Don't remove
    Game *gameClass = (Game *)game;

    if (packet.getData().size() < sizeof(int)) {
        std::cout << "Invalid packet" << std::endl;
        return;
    }
    int cmd = (int)packet;
    std::string id;
    size_t type;

    try {
        switch (cmd) {
            case rt::engine::TypeCmd::EntityComponentUpdated:
                id = (std::string)packet;
                type = (size_t)packet;
                gameClass->getWorld().getEntity(id).getComponent(type).deserialize(packet);
                gameClass->onEntityComponentUpdated(gameClass->getWorld().getEntity(id), type);
            break;
            case rt::engine::Connection:
                gameClass->engineSrv.onNewConnection();
            break;
        }
    } catch (std::exception &e) {

    }
}

Server::Server(Game *game, const std::string &ip, uint16_t port) : BoostServer(ip, port, rcvHandler)
{
    // To receive in rcvHandler
    data = game;
}

Server::~Server(void)
{

}
