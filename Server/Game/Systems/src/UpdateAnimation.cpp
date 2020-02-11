/**
 * @file UpdateAnimation.cpp
 * @author Loïc Bontemps (loic1.bontemps@epitech.eu)
 * @brief 
 * @version 1.0
 * @date 2019-12-01
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include "UpdateAnimation.hpp"
#include "Texture.hpp"

namespace rt::game::systems
{

	UpdateAnimation::UpdateAnimation(void) :
	System(
		rt::engine::getSystemType<UpdateAnimation>(),
		// Required Components
		rt::engine::ComponentList({
			rt::engine::getComponentType<rt::game::components::Texture>()
		})
	)
	{
    
    }

	void UpdateAnimation::update(float ellapsedTime)
	{
        auto entities = getApplicableEntities();

		for (auto entity : entities) {
			auto &tex = entity.get().getComponent<rt::game::components::Texture>();
            tex.nextRect(ellapsedTime);
            entity.get().syncComponent<rt::game::components::Texture>();
		}
	}

}
