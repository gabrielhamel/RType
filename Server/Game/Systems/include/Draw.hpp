/**
 * @file ApplyDamages.hpp
 * @author Jeremy Groizard (jeremy.groizard@epitech)
 * @brief ApplyDamage System
 * @version 0.1
 * @date 2019-11-28
 *
 * @copyright Copyright (c) 2019
 *
 */

#pragma once

#include "Engine.hpp"
#include <SFML/Graphics.hpp>

namespace rt::game::systems
{

	class Draw : public rt::engine::System
	{
		public:
			Draw(void);
			void update(sf::RenderWindow &window);
	};

}
