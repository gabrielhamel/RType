/**
 * @file ApplyDamages.cpp
 * @author Jeremy Groizard (jeremy.groizard@epitech)
 * @brief ApplyDamage System implementation
 * @version 0.1
 * @date 2019-11-28
 *
 * @copyright Copyright (c) 2019
 *
 */

#include <iostream>
#include "ApplyDamages.hpp"
#include "Life.hpp"
#include "Damage.hpp"

namespace rt::game::systems
{

	ApplyDamages::ApplyDamages(void) :
	System(
		rt::engine::getSystemType<ApplyDamages>(),
		// Required Components
		rt::engine::ComponentList({
			rt::engine::getComponentType<rt::game::components::Life>(),
			rt::engine::getComponentType<rt::game::components::Damage>()
		})
	)
	{

	}

	void ApplyDamages::update(void)
	{
		auto entities = getApplicableEntities();

		for (auto entity : entities) {
			try {
				auto &life = entity.get().getComponent<rt::game::components::Life>();
				auto &damage = entity.get().getComponent<rt::game::components::Damage>();
				life.hp -= damage.value;
				entity.get().removeComponent<rt::game::components::Damage>();
				if (life.hp <= 0)
					entity.get().kill();
			}
			catch (const std::exception &e) {
				std::cerr << e.what() << std::endl;
			}
		}
	}

}
