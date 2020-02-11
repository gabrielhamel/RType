/**
 * @file Transform.hpp
 * @author Jeremy Groizard (jeremy.groizard@epitech)
 * @brief Transform Component
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
	struct Transform : public AVector
	{
		Transform(float x = 0, float y = 0);
		Transform(rt::Byte packet) : AVector(packet) { }
	};

}
