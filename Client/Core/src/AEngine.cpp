/**
 * @file AEngine.cpp
 * @author Gabriel Hamel (gabriel.hamel@epitech.ey)
 * @brief
 * @version 1.0
 * @date 2019-11-20
 *
 * @copyright Copyright (c) 2019
 *
 */

#include "AEngine.hpp"

using namespace rt::game::client;

AEngine::AEngine(unsigned int width, unsigned int height, const std::string &title, unsigned int framerate, bool vSync) :
_window(sf::VideoMode(width, height), title)
{
    _window.setFramerateLimit(framerate);
    _window.setVerticalSyncEnabled(vSync);
    _window.setKeyRepeatEnabled(false);
}

AEngine::~AEngine()
{

}

void AEngine::run(void)
{
    while (_window.isOpen()) {
        _ellapsedTime = _gameTimer.restart();
        while (_window.pollEvent(_event))
            if (onEventTrigger(_event))
                _window.close();
        update(_ellapsedTime.asSeconds());
        _window.clear();
        draw(_window);
        _window.display();
    }
}
