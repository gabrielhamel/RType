/**
 * @file Bullet.cpp
 * @author Gabriel Hamel (gabriel.hamel@epitech.eu)
 * @brief
 * @version 1.0
 * @date 2020-02-08
 *
 * @copyright Copyright (c) 2020
 *
 */

#include <iostream>

#include "Bullet.hpp"

Bullet::Bullet(const sf::Sprite &shooter) : AnimatedSprite(PlayerBullet),
m_speed(1000.f), m_isDead(false)
{
    auto pos = shooter.getPosition();
    pos.x += this->getTexture()->getSize().x * 1.5f;
    this->setPosition(pos);
}

void Bullet::update(float ellapsedTime)
{
    if (this->getPosition().x > 1600) {
        this->m_isDead = true;
        return;
    }
    this->m_clock += ellapsedTime;
	if (this->m_clock >= Entities::instance().getFrameTime(this->m_type)) {
		this->m_current = (this->m_current + 1) % Entities::instance().getRects(this->m_type).size();
		this->setTextureRect(Entities::instance().getRects(this->m_type)[this->m_current]);
		this->m_clock = 0;
	}
    this->move(this->m_speed * ellapsedTime, 0);
}

bool Bullet::isDead() const
{
    return this->m_isDead;
}
