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

#pragma once

#include "Engine.hpp"

namespace rt::game::systems
{

	class EntityKiller : public rt::engine::System
	{
        public:
            EntityKiller(void);
            void update(void);
	};

}
