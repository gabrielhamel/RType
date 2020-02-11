/**
 * @file Colidable.cpp
 * @author Loïc Bontemps (loic1.bontemps@epitech.eu)
 * @brief 
 * @version 1.0
 * @date 2019-12-01
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include "Colidable.hpp"
#include "Size.hpp"
#include "Position.hpp"

namespace rt::game::systems
{

	Colidable::Colidable(void) :
	System(
		rt::engine::getSystemType<Colidable>(),
		// Required Components
		rt::engine::ComponentList({
            rt::engine::getComponentType<rt::game::components::Position>(),
			rt::engine::getComponentType<rt::game::components::Size>()
		})
	), _state(false)
	{

    }

	bool Colidable::isCollided(rt::engine::Entity r1, rt::engine::Entity r2)
	{
		auto &s1 = r1.getComponent<rt::game::components::Size>();
		auto &p1 = r1.getComponent<rt::game::components::Position>();
		auto &s2 = r2.getComponent<rt::game::components::Size>();
		auto &p2 = r2.getComponent<rt::game::components::Position>();

		if (p1.x <= p2.x + s2.x && p1.x + s1.x >= p2.x)
			if (p1.y <= p2.y + s2.y && p1.y + s1.y >= p2.y)
				return true;
		return false;
	}

}
