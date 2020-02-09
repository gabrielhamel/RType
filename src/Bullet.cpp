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

Bullet::Bullet(const sf::Sprite &shooter, Engine &engine) : AnimatedSprite(PlayerBullet, engine),
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

void Bullet::die()
{
    this->m_isDead = true;
}

static bool isCollideRect(const sf::IntRect &a, const sf::IntRect &b)
{
    return a.intersects(b);
}

bool Bullet::isCollide(const AnimatedSprite &entity) const
{
    auto entityRect = Entities::instance().getRects(entity.getType())[0];
    auto entityPos = entity.getPosition();
    entityRect.top = entityPos.x;
    entityRect.left = entityPos.y;
    entityRect.width *= 3;
    entityRect.height *= 3;
    auto meRect = Entities::instance().getRects(this->m_type)[0];
    auto mePos = this->getPosition();
    meRect.top = mePos.x;
    meRect.left = mePos.y;
    meRect.width *= 3;
    meRect.height *= 3;
    return isCollideRect(entityRect, meRect);
}
