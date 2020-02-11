/**
 * @file GameSystems.cpp
 * @author Gabriel Hamel (gabriel.hamel@epitech.eu)
 * @brief
 * @version 1.0
 * @date 2019-11-30
 *
 * @copyright Copyright (c) 2019
 *
 */

#include "GameSystems.hpp"

using namespace rt::game::systems;

void rt::game::systems::initSystems(void)
{
    rt::engine::getSystemType<rt::game::systems::ApplyDamages>();
    rt::engine::getSystemType<rt::game::systems::ApplyMovement>();
    rt::engine::getSystemType<rt::game::systems::UpdateAnimation>();
    rt::engine::getSystemType<rt::game::systems::Draw>();
    rt::engine::getSystemType<rt::game::systems::DrawLife>();
    rt::engine::getSystemType<rt::game::systems::EntityKiller>();
    rt::engine::getSystemType<rt::game::systems::Colidable>();
}

std::shared_ptr<rt::engine::System> rt::game::systems::createSystems(rt::engine::SystemType system)
{
    if (system == rt::engine::getSystemType<ApplyDamages>())
        return std::make_shared<ApplyDamages>();
    else if (system == rt::engine::getSystemType<ApplyMovement>())
        return std::make_shared<ApplyMovement>();
    else if (system == rt::engine::getSystemType<UpdateAnimation>())
        return std::make_shared<UpdateAnimation>();
    else if (system == rt::engine::getSystemType<Draw>())
        return std::make_shared<Draw>();
    else if (system == rt::engine::getSystemType<DrawLife>())
        return std::make_shared<DrawLife>();
    else if (system == rt::engine::getSystemType<EntityKiller>())
        return std::make_shared<EntityKiller>();
    else if (system == rt::engine::getSystemType<Colidable>())
        return std::make_shared<Colidable>();
    else
        throw std::runtime_error("Invalid system or not defined in SystemComponents.hpp");
}
