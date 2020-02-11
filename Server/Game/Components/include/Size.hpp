/**
 * @file Size.hpp
 * @author Jeremy Groizard (jeremy.groizard@epitech)
 * @brief Size Component
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
	struct Size : public AVector
	{
		Size(float x = 0, float y = 0);
        Size(rt::Byte packet) : AVector(packet) { }
	};

}
