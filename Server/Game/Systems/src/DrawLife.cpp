/**
 * @file DrawLife.cpp
 * @author Loïc Bontemps (loic1.bontemps@epitech.eu)
 * @brief 
 * @version 1.0
 * @date 2019-12-01
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include "DrawLife.hpp"

namespace rt::game::systems
{
	DrawLife::DrawLife(void) :
	System(
		rt::engine::getSystemType<DrawLife>(),
		// Required Components
		rt::engine::ComponentList({
			rt::engine::getComponentType<rt::game::components::Life>(),
			rt::engine::getComponentType<rt::game::components::Size>(),
			rt::engine::getComponentType<rt::game::components::Drawable>(),
			rt::engine::getComponentType<rt::game::components::Position>()
		})
	), _rectangleShape(sf::RectangleShape())
	{
		_rectangleShape.setFillColor(sf::Color::Red);
    }

	void DrawLife::draw(sf::RenderWindow &window)
	{
		auto entities = getApplicableEntities();

		for (auto entity : entities) {
			auto &life = entity.get().getComponent<rt::game::components::Life>();
			auto &size = entity.get().getComponent<rt::game::components::Size>();
			auto &position = entity.get().getComponent<rt::game::components::Position>();

			// Create rectangle Shape
			_rectangleShape.setSize(sf::Vector2f{life.getLife() * size.x / life.original_hp, 5});
			_rectangleShape.setPosition(sf::Vector2f{position.x, position.y + size.y + 5});

			window.draw(_rectangleShape);
		}
	}

}
