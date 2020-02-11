/**
 * @file EntityKiller.hpp
 * @author Gabriel Hamel (gabriel.hamel@epitech.eu)
 * @brief
 * @version 1.0
 * @date 2019-12-01
 *
 * @copyright Copyright (c) 2019
 *
 */

#include "EntityKiller.hpp"
#include "Size.hpp"
#include "Life.hpp"
#include "Position.hpp"

namespace rt::game::systems
{

	EntityKiller::EntityKiller(void) :
	System(
		rt::engine::getSystemType<EntityKiller>(),
		// Required Components
		rt::engine::ComponentList({
            rt::engine::getComponentType<rt::game::components::Position>()
		})
	)
	{

    }

	void EntityKiller::update(void)
	{
        // auto entities = getApplicableEntities();

		// for (auto entity : entities) {
        //     if (entity.get().isKilled())
        //         continue;
        //     auto &pos = entity.get().getComponent<rt::game::components::Position>();
        //     auto sizeX = 0;
        //     auto sizeY = 0;
        //     if (entity.get().hasComponent<rt::game::components::Size>()) {
        //         auto &size = entity.get().getComponent<rt::game::components::Size>();
        //         sizeX += size.x;
        //         sizeY += size.y;
        //     }
        //     if (pos.x - sizeX < 0 || pos.x > 800 || pos.y - sizeY < 0 || pos.y > 600) {
        //         entity.get().kill();
        //         continue;
        //     }
        //     if (entity.get().hasComponent<rt::game::components::Life>())
        //         if (entity.get().getComponent<rt::game::components::Life>().hp == 0) {
        //             entity.get().kill();
        //             continue;
        //         }
		// }
	}

}
