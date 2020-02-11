/**
 * @file Life.cpp
 * @author Jeremy Groizard (jeremy.groizard@epitech)
 * @brief Life Component implementation
 * @version 0.1
 * @date 2019-11-27
 *
 * @copyright Copyright (c) 2019
 *
 */

#include "Life.hpp"

namespace rt::game::components
{

	Life::Life(int hp) : hp(hp), original_hp(hp)
	{}

	Life::Life(rt::Byte &packet)
	{
		hp = static_cast<int>(packet);
		original_hp = static_cast<int>(packet);
	}

	void Life::deserialize(rt::Byte packet)
	{
		hp = static_cast<int>(packet);
		original_hp = static_cast<int>(packet);
	}

	rt::Byte Life::serialize(void) const
	{
		rt::Byte packet;

		return (packet << hp << original_hp);
	}

	float Life::getLife(void) const
	{
		return hp;
	}

}
