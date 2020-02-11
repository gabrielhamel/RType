/**
 * @file Player.cpp
 * @author Gabriel Hamel (gabriel.hamel@epitech.eu)
 * @brief
 * @version 1.0
 * @date 2019-12-01
 *
 * @copyright Copyright (c) 2019
 *
 */

#include "../include/Player.hpp"

rt::game::components::Player::Player() :
_level(0), _taken(0)
{

}

rt::game::components::Player::Player(rt::Byte &packet)
{
    _level = (int)packet;
    _taken = (int)packet;
}

rt::game::components::Player::~Player()
{

}

void rt::game::components::Player::deserialize(rt::Byte packet)
{
    _level = (int)packet;
    _taken = (int)packet;
}

rt::Byte rt::game::components::Player::serialize(void) const
{
    rt::Byte packet;
    packet << _level;
    packet << _taken;
    return packet;
}

int rt::game::components::Player::level(void) const
{
    return _level;
}

bool rt::game::components::Player::taken(void) const
{
    return _taken;
}

void rt::game::components::Player::take(void)
{
    _taken = true;
}

void rt::game::components::Player::levelUp(void)
{
    _level++;
}
