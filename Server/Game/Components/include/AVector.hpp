/**
 * @file AVector.hpp
 * @author Jeremy Groizard (jeremy.groizard@epitech)
 * @brief AVector Base Compoenent
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
	struct AVector : public rt::engine::Component
	{
		float x;
		float y;
		AVector(float x = 0, float y = 0);
		AVector(rt::Byte &packet);
		void deserialize(rt::Byte packet);
		rt::Byte serialize(void) const;

	};


}
