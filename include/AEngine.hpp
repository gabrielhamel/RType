/**
 * @file AEngine.hpp
 * @author Gabriel Hamel (gabriel.hamel@epitech.eu)
 * @brief
 * @version 1.0
 * @date 2020-02-07
 *
 * @copyright Copyright (c) 2020
 *
 */

#pragma once

#include <SFML/Graphics.hpp>

class AEngine : public sf::RenderWindow
{

private:

    sf::Time ellapsedTime;

    sf::Clock m_internalClock;

    sf::Event m_events;

    virtual void eventManager(const sf::Event &event) = 0;

    virtual void update(const sf::Time &ellapsedTime) = 0;

    virtual void draw(sf::RenderWindow &window) = 0;


public:

    AEngine(uint32_t width, uint32_t height, const std::string &title, bool vsync, uint32_t fps);

    virtual ~AEngine();

    void run();

};
