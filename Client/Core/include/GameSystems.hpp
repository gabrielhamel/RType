/**
 * @file GameSystems.hpp
 * @author Gabriel Hamel (gabriel.hamel@epitech.eu)
 * @brief
 * @version 1.0
 * @date 2019-11-30
 *
 * @copyright Copyright (c) 2019
 *
 */

#pragma once

#include "ApplyDamages.hpp"
#include "ApplyMovement.hpp"
#include "UpdateAnimation.hpp"
#include "Draw.hpp"
#include "DrawLife.hpp"
#include "EntityKiller.hpp"
#include "Colidable.hpp"

namespace rt::game::systems
{

    void initSystems(void);
    std::shared_ptr<rt::engine::System> createSystems(rt::engine::SystemType system);

}
