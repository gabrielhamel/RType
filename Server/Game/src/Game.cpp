/**
 * @file Game.cpp
 * @author Jeremy Groizard (jeremy.groizard@epitech)
 * @brief Game implementation
 * @version 0.1
 * @date 2019-11-28
 *
 * @copyright Copyright (c) 2019
 *
 */

#include <SFML/System.hpp>
#include "Game.hpp"
#include "GameComponents.hpp"
#include "GameSystems.hpp"
#include "EngineSrv.hpp"

using namespace rt::game;

Game::Game(const std::string &ip, uint16_t port) :
_handler(*this), _server(this, ip, port), _started(false), _ended(false), _world(_handler), engineSrv(*this)
{
	// Launch the server in background
	_serverLoop = std::thread(&rt::game::Server::threadLaunch, &_server);
}

Game::~Game()
{
	_server.stop();
	_serverLoop.join();
}

void Game::run(void)
{
	if (_ended || _started)
		return;
	const float refresh = 0.2f;
	_started = true;
	sf::Clock clock;
	float ellapsed;
    while (!isEnded()) {
		clock.restart();
        update(refresh);
        ellapsed = clock.getElapsedTime().asSeconds();
		sf::sleep(sf::seconds(refresh - ellapsed));
    }
	_ended = true;
}

bool Game::isStarted(void) const
{
	return _started;
}

bool Game::isEnded(void) const
{
	return _ended;
}

World &Game::getWorld(void)
{
	return _world;
}

void Game::onEntityComponentUpdated(Entity &entity, ComponentType component)
{
	engineSrv.onEntityComponentUpdated(entity, component);
}

void Game::update(float ellapsedTime)
{
	if (!_started || _ended)
		return;
	engineSrv.update(ellapsedTime);
	_world.refresh();
}

rt::game::Server &Game::getServer(void)
{
	return _server;
}
