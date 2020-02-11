/**
 * @file NetworkPack.cpp
 * @author Gabriel Hamel (gabriel.hamel@epitech.eu)
 * @brief
 * @version 1.0
 * @date 2019-11-30
 *
 * @copyright Copyright (c) 2019
 *
 */

#include "Engine.hpp"

rt::Byte rt::network::pack(rt::engine::Entity &entity)
{
    Byte packet;
    packet << entity.id.to_string();
    return packet;
}

rt::Byte rt::network::pack(rt::engine::Entity &entity, rt::engine::ComponentType component)
{
    rt::Byte packet;
    packet << entity.id.to_string();
    packet << component;
    packet += entity.getComponent(component).serialize();
    return packet;
}
