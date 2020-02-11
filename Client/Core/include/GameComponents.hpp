/**
 * @file ComponentAssociation.hpp
 * @author Gabriel Hamel (gabriel.hamel@epitech.eu)
 * @brief
 * @version 1.0
 * @date 2019-11-30
 *
 * @copyright Copyright (c) 2019
 *
 */

#pragma once

#include "AVector.hpp"
#include "Damage.hpp"
#include "Life.hpp"
#include "Speed.hpp"
#include "Texture.hpp"
#include "Transform.hpp"
#include "../../../Server/Game/Components/include/Player.hpp"
#include "Position.hpp"
#include "Size.hpp"
#include "Drawable.hpp"
#include "Enemy.hpp"

namespace rt::game::components
{

    void initComponents(void);
    std::shared_ptr<rt::engine::Component> createComponent(rt::engine::ComponentType component, Byte builder);

}
