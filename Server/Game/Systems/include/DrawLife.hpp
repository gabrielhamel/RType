/**
 * @file DrawLife.hpp
 * @author Loïc Bontemps (loic1.bontemps@epitech.eu)
 * @brief 
 * @version 1.0
 * @date 2019-12-01
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#pragma once

#include "Engine.hpp"
#include "Life.hpp"
#include "Position.hpp"
#include "Drawable.hpp"
#include "Size.hpp"
#include <SFML/Graphics.hpp>


namespace rt::game::systems
{
	class DrawLife : public rt::engine::System
	{
		private:
			sf::RectangleShape _rectangleShape;
		public:
			DrawLife(void);
			void draw(sf::RenderWindow &window);
	};

}
