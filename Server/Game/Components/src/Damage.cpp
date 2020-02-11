/**
 * @file Damage.cpp
 * @author Jeremy Groizard (jeremy.groizard@epitech)
 * @brief Damage Compoenent implementation
 * @version 0.1
 * @date 2019-11-28
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include "Damage.hpp"

namespace rt::game::components
{

	Damage::Damage(int value) : value(value)
	{}

	Damage::Damage(rt::Byte &packet)
	{
		value = static_cast<int>(packet);
	}

	void Damage::deserialize(rt::Byte packet)
	{
		value = static_cast<int>(packet);
	}

	rt::Byte Damage::serialize(void) const
	{
		rt::Byte packet;
        
		return (packet << value);
	}

}
