/**
 * @file Core.hpp
 * @author Jeremy Groizard (jeremy.groizard@epitech)
 * @brief
 * @version 0.1
 * @date 2019-11-20
 *
 * @copyright Copyright (c) 2019
 *
 */

#pragma once

#include <vector>
#include <thread>
#include "Engine.hpp"
#include "ClientListener.hpp"
#include "BoostUdp.hpp"
#include "CoreHandler.hpp"
#include "EngineCli.hpp"

namespace rt::core
{
	/**
	 * @brief The main entrypoint of the game
	 *
	 */
	class Core
	{
		private:
			/**
			 * @brief The world handler
			 *
			 */
			rt::game::client::EngineCli _engine;
			/**
			 * @brief The lister main loop
			 *
			 */
			std::thread _listenerLoop;
			/**
			 * @brief The client listener
			 *
			 */
			rt::core::ClientListener _listener;
			/**
			 * @brief To send data to the server
			 *
			 */
			rt::network::BoostUdpEndpoint _server;
			/**
			 * @brief The world of the game board
			 *
			 */
			rt::engine::World _world;
			/**
			 * @brief State of the game : started or not
			 *
			 */
			bool _started;
			/**
			 * @brief State of the game : ended or not
			 *
			 */
			bool _ended;
		public:
			/**
			 * @brief Construct a new Game object
			 *
			 */
			Core(const std::string &serverIp, uint16_t serverPort, const std::string &myIp, uint16_t myPort);
			/**
			 * @brief Destroy the Game object
			 *
			 */
			~Core();
			/**
			 * @brief Start the game
			 *
			 */
			void run(void);
			/**
			 * @brief Get World
			 *
			 * @return rt::engine::World&
			 */
			rt::engine::World &getWorld(void);
			/**
			 * @brief Get Server
			 *
			 * @return rt::network::BoostUdpEndpoint&
			 */
			rt::network::BoostUdpEndpoint &getServer(void) { return _server; }
	};

}
