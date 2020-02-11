/**
 * @file Life.hpp
 * @author Jeremy Groizard (jeremy.groizard@epitech)
 * @brief Life Component
 * @version 0.1
 * @date 2019-11-27
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#pragma once

#include "Engine.hpp"

namespace rt::game::components
{
	struct Life : public rt::engine::Component
	{
		int hp;
		int original_hp;
		Life(int hp = 100);
		Life(rt::Byte &packet);
		void deserialize(rt::Byte packet);
		rt::Byte serialize(void) const;
		float getLife(void) const;
	};

}
