/**
 * @file ApplyMovement.cpp
 * @author Jeremy Groizard (jeremy.groizard@epitech)
 * @brief ApplyMovement System
 * @version 0.1
 * @date 2019-11-29
 *
 * @copyright Copyright (c) 2019
 *
 */

#include <iostream>
#include "ApplyMovement.hpp"
#include "Position.hpp"
#include "Drawable.hpp"
#include "Speed.hpp"

namespace rt::game::systems
{

	ApplyMovement::ApplyMovement(void) :
	System(
		rt::engine::getSystemType<ApplyMovement>(),
		// Required Components
		rt::engine::ComponentList({
			rt::engine::getComponentType<rt::game::components::Position>(),
			rt::engine::getComponentType<rt::game::components::Speed>()
		})
	)
	{

	}

	void ApplyMovement::update(float ellapsedTime)
	{
		auto entities = getApplicableEntities();

		for (auto entity : entities) {
			auto &position = entity.get().getComponent<rt::game::components::Position>();
			auto &speed = entity.get().getComponent<rt::game::components::Speed>();
			position.x += speed.x * ellapsedTime;
			position.y += speed.y * ellapsedTime;
			if (entity.get().hasComponent<rt::game::components::Drawable>()) {
				auto &drawable = entity.get().getComponent<rt::game::components::Drawable>();
				if (drawable.initialized) {
					if ((size_t)(drawable.object.get()) != 0)
						drawable.object.get()->setPosition(position.x, position.y);
				}
			}
		}
	}

}
