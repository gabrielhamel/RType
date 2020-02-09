/**
 * @file Player.cpp
 * @author Gabriel Hamel (gabriel.hamel@epitech.eu)
 * @brief
 * @version 1.0
 * @date 2020-02-08
 *
 * @copyright Copyright (c) 2020
 *
 */

#include <iostream>

#include "Engine.hpp"
#include "Player.hpp"

static const sf::IntRect frames[] = {
    {0, 0, 33, 17},
    {33, 0, 33, 17},
    {66, 0, 33, 17},
    {99, 0, 33, 17},
    {132, 0, 33, 17}
};

Player::Player(Engine &engine) :
m_engine(engine), m_soundShot()
{
    this->m_texture.loadFromFile("assets/vessel.gif");
    this->setTexture(this->m_texture);
    this->setTextureNo(2);
    this->setScale(3, 3);
    this->setPosition(0, 0);
    this->setOnShot(false);
    this->m_bulletTime = 0;
    this->m_soundBuffer.loadFromFile("assets/shoot.wav");
    this->m_soundShot.setBuffer(this->m_soundBuffer);
}

void Player::setTextureNo(unsigned int nb)
{
    this->setTextureRect(frames[nb]);
}

void Player::update(float ellaspedTime)
{
    auto inc = sf::Vector2f(this->m_speedX * ellaspedTime, this->m_speedY * ellaspedTime);
    auto pos = this->getPosition();
    auto size = sf::Vector2f(33 * 3, 17 * 3);
    if (pos.x + size.x + inc.x >= 1600 || pos.x + inc.x < 0)
        inc.x = 0;
    if (pos.y + size.y + inc.y >= 900 || pos.y + inc.y < 0)
        inc.y = 0;
    this->move(inc);
    m_bulletTime += ellaspedTime;
    if (this->m_shot && this->m_bulletTime >= 0.2f) {
        this->m_bulletTime = 0.f;
        m_engine.makeShot(*this);
    }
}

void Player::setSpeedX(float x)
{
    this->m_speedX = x * 400.f;
}

void Player::setSpeedY(float y)
{
    this->m_speedY = y * 400.f;
    int res = (y + 1.f) * 2.f;
    this->setTextureNo(4 - res);
}

void Player::setOnShot(bool enable)
{
    this->m_soundShot.setLoop(enable);
    if (enable == true)
        this->m_soundShot.play();
    this->m_shot = enable;
    this->m_bulletTime = 0.2f;
}

float Player::getSpeedX() const
{
    return this->m_speedX;
}

float Player::getSpeedY() const
{
    return this->m_speedY;
}
