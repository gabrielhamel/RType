/**
 * @file Speed.hpp
 * @author Jeremy Groizard (jeremy.groizard@epitech)
 * @brief Speed Component
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
	struct Speed : public AVector
	{
		Speed(float x = 0, float y = 0);
		Speed(rt::Byte packet) : AVector(packet) { }
	};

}
