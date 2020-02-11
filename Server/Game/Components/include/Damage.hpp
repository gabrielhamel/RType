/**
 * @file Damage.hpp
 * @author Jeremy Groizard (jeremy.groizard@epitech)
 * @brief Damage Component
 * @version 0.1
 * @date 2019-11-28
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#pragma once

#include "Engine.hpp"

namespace rt::game::components
{
	struct Damage : public rt::engine::Component
	{
		int value;
		Damage(int value = 20);
		Damage(rt::Byte &packet);
		void deserialize(rt::Byte packet);
		rt::Byte serialize(void) const;

	};

}
