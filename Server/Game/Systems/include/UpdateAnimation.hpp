/**
 * @file UpdateAnimation.hpp
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

	class UpdateAnimation : public rt::engine::System
	{
        public:
            UpdateAnimation(void);
            void update(float ellapsedTime);
	};

}
