/**
 * @file AVector.cpp
 * @author Jeremy Groizard (jeremy.groizard@epitech)
 * @brief AVector Base Component implementation
 * @version 0.1
 * @date 2019-11-28
 *
 * @copyright Copyright (c) 2019
 *
 */

#include <iostream>
#include "AVector.hpp"

namespace rt::game::components
{

	AVector::AVector(float x, float y) : x(x), y(y)
	{

	}

	AVector::AVector(rt::Byte &packet)
	{
		x = static_cast<float>(packet);
        y = static_cast<float>(packet);
	}

	void AVector::deserialize(rt::Byte packet)
	{
		x = static_cast<float>(packet);
        y = static_cast<float>(packet);
	}

	rt::Byte AVector::serialize(void) const
	{
		rt::Byte packet;

		packet << x;
		packet << y;
		return packet;
	}

}
