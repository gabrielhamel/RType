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

namespace rt::game::systems
{

	/**
	 * @brief ApplyDamage System declaration
	 * 
	 */
	class ApplyDamages : public rt::engine::System
	{

	public:
		/**
		 * @brief Construct a new Apply Damages object
		 * 
		 */
		ApplyDamages(void);

		/**
		 * @brief Update entities
		 * 
		 */
		void update(void);
	
	};

}