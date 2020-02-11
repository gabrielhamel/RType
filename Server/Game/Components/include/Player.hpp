/**
 * @file Player.hpp
 * @author Gabriel Hamel (gabriel.hamel@epitech.eu)
 * @brief
 * @version 1.0
 * @date 2019-12-01
 *
 * @copyright Copyright (c) 2019
 *
 */

#pragma once

#include "Engine.hpp"

namespace rt::game::components
{
	class Player : public rt::engine::Component
	{
		public:
			Player();
			Player(rt::Byte &packet);
			~Player();
			void deserialize(rt::Byte packet);
			rt::Byte serialize(void) const;
			int level(void) const;
			bool taken(void) const;
			void take(void);
			void levelUp(void);
		private:
			int _level;
			int _taken; // is taken by a player
	};

}
