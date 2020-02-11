/**
 * @file Draw.cpp
 * @author Gabriel Hamel (gabriel.hamel@epitech.eu)
 * @brief
 * @version 1.0
 * @date 2019-12-01
 *
 * @copyright Copyright (c) 2019
 *
 */

#include "Draw.hpp"
#include "Size.hpp"
#include "Position.hpp"
#include "Drawable.hpp"

namespace rt::game::systems
{

	Draw::Draw(void) :
	System(
		rt::engine::getSystemType<Draw>(),
		// Required Components
		rt::engine::ComponentList({
            rt::engine::getComponentType<rt::game::components::Position>(),
            rt::engine::getComponentType<rt::game::components::Drawable>(),
			rt::engine::getComponentType<rt::game::components::Size>()
		})
	)
	{

    }

	void Draw::update(sf::RenderWindow &window)
	{
        auto entities = getApplicableEntities();

		for (auto entity : entities) {
			auto drawable = entity.get().getComponent<rt::game::components::Drawable>().object;
			if (drawable.get() != 0)
            	window.draw(*drawable);
		}
	}

}
