/**
 * @file ClientListener.cpp
 * @author Gabriel Hamel (gabriel.hamel@epitech.eu)
 * @brief
 * @version 1.0
 * @date 2019-11-30
 *
 * @copyright Copyright (c) 2019
 *
 */

#include "Core.hpp"
#include "Engine.hpp"

using namespace rt::core;

static void rcvHandler(rt::network::BoostUdpEndpoint &sender, rt::Byte packet, void *core)
{
    Core *coreClass = (Core *)core;

    int cmd = (int)packet;
    std::string id;
    size_t type;
    auto &srv = coreClass->getServer();

    switch (cmd) {
        case rt::engine::TypeCmd::EntityCreated:
            coreClass->getWorld().createEntity((std::string)packet, {srv});
        break;
        case rt::engine::TypeCmd::EntityKilled:
            coreClass->getWorld().getEntity((std::string)packet, srv).kill();
        break;
        case rt::engine::TypeCmd::EntityActivated:
            coreClass->getWorld().getEntity((std::string)packet, srv).activate();
        break;
        case rt::engine::TypeCmd::EntityDesactivated:
            coreClass->getWorld().getEntity((std::string)packet, srv).desactivate();
        break;
        case rt::engine::TypeCmd::EntityComponentCreated:
            id = (std::string)packet;
            type = (size_t)packet;
            coreClass->getWorld().getEntity(id, srv).addComponent(type, packet);
        break;
        case rt::engine::TypeCmd::EntityComponentUpdated:
            id = (std::string)packet;
            type = (size_t)packet;
            if (!coreClass->getWorld().getEntity(id, srv).hasComponent(type))
                coreClass->getWorld().getEntity(id, srv).addComponent(type, packet);
            else
                coreClass->getWorld().getEntity(id, srv).getComponent(type).deserialize(packet);
            coreClass->getWorld().getHandler().onEntityComponentUpdated(coreClass->getWorld().getEntity(id, srv), type);
        break;
        case rt::engine::TypeCmd::EntityComponentRemoved:
            id = (std::string)packet;
            type = (size_t)packet;
            if (coreClass->getWorld().getEntity(id, srv).hasComponent(type))
                coreClass->getWorld().getEntity(id, srv).removeComponent(type);
        break;
        case rt::engine::TypeCmd::SystemAdded:
            type = (size_t)packet;
            coreClass->getWorld().addSystem(type);
        break;
        case rt::engine::TypeCmd::SystemRemoved:
            type = (size_t)packet;
            if (!coreClass->getWorld().hasSystem(type))
                return;
            coreClass->getWorld().removeSystem(type);
        break;
        case rt::engine::TypeCmd::SystemEntityAdded:
            id = (std::string)packet;
            type = (size_t)packet;
            if (!coreClass->getWorld().hasSystem(type))
                coreClass->getWorld().addSystem(type);
            coreClass->getWorld().getSystem(type).addEntity(coreClass->getWorld().getEntity(id, srv));
        break;
        case rt::engine::TypeCmd::SystemEntityRemoved:
            id = (std::string)packet;
            type = (size_t)packet;
            if (!coreClass->getWorld().hasSystem(type)) {
                coreClass->getWorld().addSystem(type);
                return;
            }
            coreClass->getWorld().getSystem(type).removeEntity(coreClass->getWorld().getEntity(id, srv));
        break;

    };
}

ClientListener::ClientListener(Core *core, const std::string &ip, uint16_t port) : BoostServer(ip, port, rcvHandler)
{
    // To receive in rcvHandler
    data = core;
}

ClientListener::~ClientListener(void)
{

}
