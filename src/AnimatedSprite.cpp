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

#include "AnimatedSprite.hpp"

AnimatedSprite::AnimatedSprite(Entity entity) :
m_type(entity), m_current(0), m_clock(0)
{
	this->setTexture(Entities::instance().getTexture(entity));
	this->setTextureRect(Entities::instance().getRects(entity)[this->m_current]);
	this->setScale(3, 3);
	this->setPosition(0, 0);
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
}
