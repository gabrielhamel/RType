/**
 * @file AEngine.cpp
 * @author Gabriel Hamel (gabriel.hamel@epitech.eu)
 * @brief
 * @version 1.0
 * @date 2020-02-07
 *
 * @copyright Copyright (c) 2020
 *
 */

#include <iostream>

#include "AEngine.hpp"

AEngine::AEngine(unsigned int width, unsigned int height, const std::string &title, bool vsync, unsigned int fps) :
sf::RenderWindow(sf::VideoMode(width, height), title)
{
    this->setFramerateLimit(fps);
    this->setVerticalSyncEnabled(vsync);
}

AEngine::~AEngine()
{

}

void AEngine::run()
{
    this->m_internalClock.restart();
    while (this->isOpen()) {
        ellapsedTime = this->m_internalClock.restart();
        while (this->pollEvent(this->m_events)) {
            if (this->m_events.type == sf::Event::Closed)
                this->close();
            this->eventManager(this->m_events);
        }
        this->update(this->ellapsedTime);
        this->clear();
        this->draw(*this);
        this->display();
    }
}
