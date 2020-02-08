/**
 * @file Engine.cpp
 * @author Gabriel Hamel (gabriel.hamel@epitech.eu)
 * @brief
 * @version 1.0
 * @date 2020-02-07
 *
 * @copyright Copyright (c) 2020
 *
 */

#include <iostream>
#include <algorithm>

#include "Engine.hpp"

Engine::Engine(unsigned int width, unsigned int height, const std::string &title, bool vsync, unsigned int fps) :
AEngine(width, height, title, vsync, fps), m_player(*this)
{
    Entities::instance();
    this->m_background.addLayer("assets/parallax/parallax-space-background.png", 50);
    this->m_background.addLayer("assets/parallax/parallax-space-far-planets.png", 70);
    this->m_background.addLayer("assets/parallax/parallax-space-stars.png", 100);
    this->m_background.addLayer("assets/parallax/parallax-space-big-planet.png", 160);
    this->m_background.addLayer("assets/parallax/parallax-space-ring-planet.png", 160);

    this->m_player.setPosition(20, 290);
}

Engine::~Engine()
{

}

void Engine::eventManager(const sf::Event &event)
{
    switch (event.type) {
        case sf::Event::JoystickButtonPressed:
            if (event.joystickButton.button == 0)
                this->m_player.setOnShot(true);
        break;
        case sf::Event::JoystickButtonReleased:
            if (event.joystickButton.button == 0)
                this->m_player.setOnShot(false);
        break;
        case sf::Event::JoystickMoved:
            const auto &axis = event.joystickMove.axis;
            switch (axis) {
                case sf::Joystick::Axis::X:
                    this->m_player.setSpeedX(TRUNC_FLOAT(event.joystickMove.position, 10));
                break;
                case sf::Joystick::Axis::Y:
                    this->m_player.setSpeedY(TRUNC_FLOAT(event.joystickMove.position, 10));
                break;
            }
        break;
    }
}

void Engine::update(const sf::Time &ellapsedTime)
{
    this->m_background.update(ellapsedTime.asSeconds());
    for (auto bullet = this->m_player_bullets.begin(); bullet != this->m_player_bullets.end(); bullet++) {
        (*bullet)->update(ellapsedTime.asSeconds());
        if ((*bullet)->isDead())
            bullet = this->m_player_bullets.erase(bullet);
    }
    for (auto &entity : this->m_sprites)
        entity->update(ellapsedTime.asSeconds());
    m_player.update(ellapsedTime.asSeconds());
}

void Engine::draw(sf::RenderWindow &window)
{
    this->m_background.draw(window);
    for (auto &bullet : this->m_player_bullets)
        window.draw(*bullet);
    for (const auto &entity : this->m_sprites)
        window.draw(*entity);
    window.draw(this->m_player);
}

void Engine::makeShot(const sf::Sprite &shooter)
{
    this->m_player_bullets.push_back(std::make_unique<Bullet>(shooter));
}
