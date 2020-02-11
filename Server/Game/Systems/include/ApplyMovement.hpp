/**
 * @file ApplyMovement.hpp
 * @author Jeremy Groizard (jeremy.groizard@epitech)
 * @brief ApplyMovement System
 * @version 0.1
 * @date 2019-11-29
 *
 * @copyright Copyright (c) 2019
 *
 */

#pragma once

#include "Engine.hpp"

namespace rt::game::systems
{

	class ApplyMovement : public rt::engine::System
	{

	public:
		/**
		 * @brief Construct a new Apply Movement object
		 *
		 */
		ApplyMovement(void);

		/**
		 * @brief Update entities
		 *
		 */
		void update(float ellapsedTime);

	};

}
