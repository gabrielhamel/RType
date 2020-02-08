/**
 * @file Engine.hpp
 * @author Gabriel Hamel (gabriel.hamel@epitech.eu)
 * @brief
 * @version 1.0
 * @date 2020-02-07
 *
 * @copyright Copyright (c) 2020
 *
 */

#pragma once

#include <list>

#include "AEngine.hpp"
#include "AnimatedSprite.hpp"
#include "Player.hpp"
#include "Bullet.hpp"
#include "Parallax.hpp"

#define TRUNC_FLOAT(x, dec) (((float)(int)((float)(int)x / dec)) / dec)

class Engine : public AEngine
{

private:

    sf::Vector2f m_joystick;

    std::vector<std::unique_ptr<AnimatedSprite>> m_sprites;

    Player m_player;

    std::list<std::unique_ptr<Bullet>> m_player_bullets;

    Parallax m_background;

    void eventManager(const sf::Event &event);

    void update(const sf::Time &ellapsedTime);

    void draw(sf::RenderWindow &window);

public:

    Engine(uint32_t width, uint32_t height, const std::string &title = "", bool vsync = true, uint32_t fps = 60);

    ~Engine();

    void makeShot(const sf::Sprite &shooter);

};
