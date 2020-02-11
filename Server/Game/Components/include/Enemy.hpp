/**
 * @file Enemy.hpp
 * @author Loïc Bontemps (loic1.bontemps@epitech.eu)
 * @brief 
 * @version 1.0
 * @date 2019-12-01
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#pragma once

#include "Engine.hpp"

namespace rt::game
{
    enum EnemyType
    {
        Common = 1,
        Rare,
        Epic,
        Boss
    };

}

namespace rt::game::components
{
	class Enemy : public rt::engine::Component
	{
		private:
			rt::game::EnemyType _type;
		public:
			Enemy(rt::game::EnemyType type);
			Enemy(rt::Byte &packet);
			~Enemy();
			void deserialize(rt::Byte packet);
			rt::Byte serialize(void) const;
	};

}
