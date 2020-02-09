/**
 * @file Texture.cpp
 * @author Jeremy Groizard (jeremy.groizard@epitech)
 * @brief Texture Component implementation
 * @version 0.1
 * @date 2019-11-29
 *
 * @copyright Copyright (c) 2019
 *
 */

#include <iostream>

#include "Engine.hpp"

AnimatedSprite::AnimatedSprite(Entity entity, Engine &engine) :
m_engine(engine), m_type(entity), m_current(0), m_clock(0), speedX(0), speedY(0), isDead(false), m_life(100)
{
	this->setTexture(Entities::instance().getTexture(entity));
	this->setTextureRect(Entities::instance().getRects(entity)[this->m_current]);
	this->setScale(3, 3);
	this->setPosition(0, 0);
	auto size = Entities::instance().getRects(entity)[0];
	size.width *= 3;
	size.height *= 3;
	this->m_lifeBar.setFillColor(sf::Color::Red);
	this->m_lifeBar.setPosition(sf::Vector2f(0, size.height));
	this->m_lifeBar.setSize(sf::Vector2f(size.width, 10));
}

AnimatedSprite::~AnimatedSprite()
{

}

void AnimatedSprite::update(float ellapsedTime)
{
	this->m_clock += ellapsedTime;
	if (this->m_clock >= Entities::instance().getFrameTime(this->m_type)) {
		this->m_current = (this->m_current + 1) % Entities::instance().getRects(this->m_type).size();
		this->setTextureRect(Entities::instance().getRects(this->m_type)[this->m_current]);
		this->m_clock = 0;
	}
	this->moveX(this->speedX * ellapsedTime);
	this->moveY(this->speedY * ellapsedTime);
}

void AnimatedSprite::draw(sf::RenderWindow &window)
{
	window.draw(this->m_lifeBar);
}

void AnimatedSprite::moveX(float value)
{
	this->move(value, 0);
	this->m_lifeBar.move(value, 0);
}

void AnimatedSprite::moveY(float value)
{
	this->move(0, value);
	this->m_lifeBar.move(0, value);
}

void AnimatedSprite::takeDamage(float amount)
{
	this->m_life -= (amount - Entities::instance().getDefense(this->m_type));
	auto size = Entities::instance().getRects(this->m_type)[0];
	size.width *= 3;
	size.height *= 3;
	this->m_lifeBar.setFillColor(sf::Color::Red);
	this->m_lifeBar.setSize(sf::Vector2f(size.width * (this->m_life / 100.f), 10));
	if (this->m_life <= 0) {
		this->isDead = true;
			this->m_engine.explode();
	}
}

Entity AnimatedSprite::getType() const
{
	return this->m_type;
}
