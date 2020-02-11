/**
 * @file Enemy.cpp
 * @author Loïc Bontemps (loic1.bontemps@epitech.eu)
 * @brief 
 * @version 1.0
 * @date 2019-12-01
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include "Enemy.hpp"

namespace rt::game::components
{

	Enemy::Enemy(rt::game::EnemyType type): _type(type)
	{

	}

	Enemy::Enemy(rt::Byte &packet)
	{
		_type = (rt::game::EnemyType)static_cast<int>(packet);
	}

	Enemy::~Enemy()
	{
	
	}
	
	void Enemy::deserialize(rt::Byte packet)
	{
		_type = (rt::game::EnemyType)static_cast<int>(packet);
	}
	
	rt::Byte Enemy::serialize(void) const
	{
		rt::Byte packet;

		return (packet << _type);
	}

}
