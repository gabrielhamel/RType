/**
 * @file EngineCli.cpp
 * @author Gabriel Hamel (gabriel.hamel@epitech.ey)
 * @brief
 * @version 1.0
 * @date 2019-11-20
 *
 * @copyright Copyright (c) 2019
 *
 */

#include "EngineCli.hpp"
#include "Core.hpp"

using namespace rt::game::client;
using namespace rt::game::components;
using namespace rt::game::systems;

EngineCli::EngineCli(rt::core::Core &core) : CoreHandler(core),
_core(core), AEngine(800, 600, "RType", 60, true),  _framerate(60), _world(core.getWorld()),
_noPlayerBind(true)
{

}

EngineCli::~EngineCli()
{

}

bool EngineCli::onEventTrigger(sf::Event &event)
{
    if (event.type == sf::Event::Closed)
        return true;
    if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Escape)
            return true;
        else if (event.key.code == sf::Keyboard::Q) {
            auto &entity = _world.getEntity(_me);
            auto &speed = entity.getComponent<Speed>();
            speed.x = -100;
            entity.syncComponent<Speed>();
        }
        else if (event.key.code == sf::Keyboard::D) {
            auto &entity = _world.getEntity(_me);
            auto &speed = entity.getComponent<Speed>();
            speed.x = 100;
            entity.syncComponent<Speed>();
        }
        else if (event.key.code == sf::Keyboard::Z) {
            auto &entity = _world.getEntity(_me);
            auto &speed = entity.getComponent<Speed>();
            speed.y = -100;
            entity.syncComponent<Speed>();
        }
        else if (event.key.code == sf::Keyboard::S) {
            auto &entity = _world.getEntity(_me);
            auto &speed = entity.getComponent<Speed>();
            speed.y = 100;
            entity.syncComponent<Speed>();
        }
    }
    else if (event.type == sf::Event::KeyReleased) {
        if (event.key.code == sf::Keyboard::Q) {
            auto &entity = _world.getEntity(_me);
            auto &speed = entity.getComponent<Speed>();
            speed.x = 0;
            entity.syncComponent<Speed>();
        }
        else if (event.key.code == sf::Keyboard::D) {
            auto &entity = _world.getEntity(_me);
            auto &speed = entity.getComponent<Speed>();
            speed.x = 0;
            entity.syncComponent<Speed>();
        }
        else if (event.key.code == sf::Keyboard::Z) {
            auto &entity = _world.getEntity(_me);
            auto &speed = entity.getComponent<Speed>();
            speed.y = 0;
            entity.syncComponent<Speed>();
        }
        else if (event.key.code == sf::Keyboard::S) {
            auto &entity = _world.getEntity(_me);
            auto &speed = entity.getComponent<Speed>();
            speed.y = 0;
            entity.syncComponent<Speed>();
        }
    }
    return false;
}

void EngineCli::draw(sf::RenderWindow &window)
{
    if (_world.hasSystem<Draw>())
        _world.getSystem<Draw>().update(_window);
    if (_world.hasSystem<DrawLife>())
        _world.getSystem<DrawLife>().draw(_window);
}

void EngineCli::update(float ellapsedTime)
{
    if (_world.hasSystem<ApplyMovement>())
        _world.getSystem<ApplyMovement>().update(ellapsedTime);
    _world.refresh();
}

void EngineCli::bindPlayer(Entity &entity)
{
    auto &player = entity.getComponent<rt::game::components::Player>();
    if (player.taken())
        return;
    player.take();
    entity.syncComponent<rt::game::components::Player>();
    _me = entity.id.to_string();
    _noPlayerBind = false;
}

void EngineCli::onEntityComponentAdded(Entity &entity, ComponentType component)
{
    onEntityComponentUpdated(entity, component);
}

void EngineCli::onEntityComponentUpdated(Entity &entity, ComponentType component)
{
    if (component == getComponentType<rt::game::components::Player>()) {
        if (_noPlayerBind)
            bindPlayer(entity);
    }
    else if (component == getComponentType<Position>()) {
        auto &pos = entity.getComponent<Position>();
        if (entity.hasComponent<Drawable>()) {
            auto &drawable = entity.getComponent<Drawable>();
            if (drawable.initialized) {
                void *ptr = drawable.object.get();
                if (ptr)
                    drawable.object->setPosition(pos.x, pos.y);
            }
        }
    }
    else if (component == getComponentType<Size>()) {
        auto &size = entity.getComponent<Size>();
        if (entity.hasComponent<Drawable>()) {
            auto &drawable = entity.getComponent<Drawable>();
            if (drawable.initialized)
                drawable.object->setSize(sf::Vector2f(size.x, size.y));
        }
    }
    else if (component == getComponentType<Drawable>()) {
        auto &drawable = entity.getComponent<Drawable>();
        if (drawable.initialized == false) {
            drawable.object = std::make_shared<sf::RectangleShape>();
            if (entity.hasComponent<Texture>()) {
                drawable.texture = entity.getComponent<Texture>().instance();
                drawable.object->setTexture(drawable.texture.get());
            }
            else
                drawable.object->setFillColor(sf::Color::Green);
            drawable.initialized = true;
        }
        if (entity.hasComponent<Texture>()) {
            void *ptr = drawable.object.get();
            if ((size_t)ptr != 0)
                drawable.object->setTextureRect(entity.getComponent<Texture>().getRect());
        }
    }
}
