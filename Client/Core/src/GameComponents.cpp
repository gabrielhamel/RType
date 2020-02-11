/**
 * @file GameComponents.cpp
 * @author Gabriel Hamel (gabriel.hamel@epitech.eu)
 * @brief
 * @version 1.0
 * @date 2019-11-30
 *
 * @copyright Copyright (c) 2019
 *
 */

#include "GameComponents.hpp"
#include "Byte.hpp"

using namespace rt::game::components;

void rt::game::components::initComponents(void)
{
    rt::engine::getComponentType<rt::game::components::AVector>();
    rt::engine::getComponentType<rt::game::components::Texture>();
    rt::engine::getComponentType<rt::game::components::Damage>();
    rt::engine::getComponentType<rt::game::components::Life>();
    rt::engine::getComponentType<rt::game::components::Speed>();
    rt::engine::getComponentType<rt::game::components::Transform>();
    rt::engine::getComponentType<rt::game::components::Player>();
    rt::engine::getComponentType<rt::game::components::Position>();
    rt::engine::getComponentType<rt::game::components::Size>();
    rt::engine::getComponentType<rt::game::components::Drawable>();
    rt::engine::getComponentType<rt::game::components::Enemy>();
}

std::shared_ptr<rt::engine::Component> rt::game::components::createComponent(rt::engine::ComponentType component, rt::Byte builder)
{
    if (component == rt::engine::getComponentType<AVector>())
        return std::make_shared<AVector>(builder);
    else if (component == rt::engine::getComponentType<Texture>())
        return std::make_shared<Texture>(builder);
    else if (component == rt::engine::getComponentType<Damage>())
        return std::make_shared<Damage>(builder);
    else if (component == rt::engine::getComponentType<Life>())
        return std::make_shared<Life>(builder);
    else if (component == rt::engine::getComponentType<Speed>())
        return std::make_shared<Speed>(builder);
    else if (component == rt::engine::getComponentType<Transform>())
        return std::make_shared<Transform>(builder);
    else if (component == rt::engine::getComponentType<Player>())
        return std::make_shared<Player>(builder);
    else if (component == rt::engine::getComponentType<Position>())
        return std::make_shared<Position>(builder);
    else if (component == rt::engine::getComponentType<Size>())
        return std::make_shared<Size>(builder);
    else if (component == rt::engine::getComponentType<Drawable>())
        return std::make_shared<Drawable>(builder);
    else if (component == rt::engine::getComponentType<Enemy>())
        return std::make_shared<Enemy>(builder);
    else
        throw std::runtime_error("Invalid component or not defined in GameComponents.hpp");
}
