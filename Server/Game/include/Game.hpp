/**
 * @file Game.hpp
 * @author Jeremy Groizard (jeremy.groizard@epitech)
 * @brief Game object - Represent a match with a game board
 * @version 0.1
 * @date 2019-11-28
 *
 * @copyright Copyright (c) 2019
 *
 */

#pragma once

#include <vector>
#include <thread>
#include "Engine.hpp"
#include "GameServer.hpp"
#include "GameHandler.hpp"
#include "EngineSrv.hpp"

namespace rt::game
{
	/**
	 * @brief Game declaration - This object represent a match with the game board
	 *
	 */
	class Game
	{
		private:
			/**
			 * @brief The world handler
			 *
			 */
			GameHandler _handler;
			/**
			 * @brief The thread for the server
			 *
			 */
			std::thread _serverLoop;
			/**
			 * @brief The game server
			 *
			 */
			rt::game::Server _server;
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
			 * @brief The game
			 *
			 */
			rt::game::srv::EngineSrv engineSrv;
			/**
			 * @brief Construct a new Game object
			 *
			 */
			Game(const std::string &ip, uint16_t port);
			/**
			 * @brief Destroy the Game object
			 *
			 */
			~Game();

			/**
			 * @brief Start the game
			 *
			 */
			void run(void);
			/**
			 * @brief Check if the game was started
			 *
			 * @return true
			 * @return false
			 */
			bool isStarted(void) const;
			/**
			 * @brief Check if the game was ended
			 *
			 * @return true
			 * @return false
			 */
			bool isEnded(void) const;
			/**
			 * @brief Update the game
			 *
			 */
			void update(float ellapsedTime);
			/**
			 * @brief Get Server
			 *
			 * @return rt::game::Server&
			 */
			rt::game::Server &getServer(void);
			/**
			 * @brief Get World
			 *
			 * @return World&
			 */
			World &getWorld(void);
			/**
			 * @brief Call when a client do an update
			 *
			 * @param entity
			 * @param component
			 */
			void onEntityComponentUpdated(Entity &entity, ComponentType component);
	};

}
