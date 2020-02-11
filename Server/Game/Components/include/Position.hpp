/**
 * @file Position.hpp
 * @author Jeremy Groizard (jeremy.groizard@epitech)
 * @brief Position Component
 * @version 0.1
 * @date 2019-11-28
 *
 * @copyright Copyright (c) 2019
 *
 */

#pragma once

#include "Engine.hpp"
#include "AVector.hpp"

namespace rt::game::components
{
	struct Position : public AVector
	{
		Position(float x = 0, float y = 0);
		Position(rt::Byte packet) : AVector(packet) { }
	};

}
