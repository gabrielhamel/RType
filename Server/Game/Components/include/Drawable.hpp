/**
 * @file Drawable.hpp
 * @author Loïc Bontemps (loic1.bontemps@epitech.eu)
 * @brief
 * @version 1.0
 * @date 2019-12-01
 *
 * @copyright Copyright (c) 2019
 *
 */

#pragma once

#include <SFML/Graphics.hpp>
#include "Engine.hpp"

namespace rt::game::components
{
	class Drawable : public rt::engine::Component
	{
		public:
			Drawable();
			Drawable(rt::Byte &packet);
			void deserialize(rt::Byte packet);
			rt::Byte serialize(void) const;
			~Drawable();
			std::shared_ptr<sf::RectangleShape> object;
			std::shared_ptr<sf::Texture> texture;
			bool initialized;
	};

}
