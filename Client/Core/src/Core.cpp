/**
 * @file Core.cpp
 * @author Jeremy Groizard (jeremy.groizard@epitech)
 * @brief
 * @version 0.1
 * @date 2019-11-20
 *
 * @copyright Copyright (c) 2019
 *
 */

#include "Core.hpp"
#include "EngineCli.hpp"
#include "GameSystems.hpp"

using namespace rt::core;

Core::Core(const std::string &serverIp, uint16_t serverPort, const std::string &myIp, uint16_t myPort) :
_engine(*this), _listener(this, myIp, myPort), _started(false), _ended(false), _server(serverIp, serverPort, myIp, myPort), _world(_engine)
{
	// Init components and systems
	rt::game::components::initComponents();
	rt::game::systems::initSystems();

	// Launch the server listener
	_listenerLoop = std::thread(&rt::core::ClientListener::threadLaunch, &_listener);

	// Send a connection packet to inform the server
	Byte packet;
	packet << rt::engine::TypeCmd::Connection;
	_server.send(packet);
}

Core::~Core()
{
	_listener.stop();
	_listenerLoop.join();
}

void Core::run(void)
{
	_engine.run();
}

rt::engine::World &Core::getWorld(void)
{
	return _world;
}
