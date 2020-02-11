/**
 * @file Colidable.hpp
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

namespace rt::game::systems
{

	class Colidable : public rt::engine::System
	{
		private:
			bool _state;
		public:
			Colidable(void);
			bool isCollided(rt::engine::Entity r1, rt::engine::Entity r2);
	};

}
