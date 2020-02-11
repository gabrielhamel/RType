/**
 * @file AEngine.hpp
 * @author Gabriel Hamel (gabriel.hamel@epitech.ey)
 * @brief The Game AEngine
 * @version 1.0
 * @date 2019-11-20
 *
 * @copyright Copyright (c) 2019
 *
 */

#pragma once

#include <SFML/Graphics.hpp>

namespace rt::game::client
{
    /**
     * @brief The main class of the Game AEngine
     *
     */
    class AEngine
    {
        protected:
            /**
             * @brief The sfml window object
             *
             */
            sf::RenderWindow _window;
            /**
             * @brief The sfml event object
             *
             */
            sf::Event _event;
            /**
             * @brief Compute ellapsed time between each frame
             *
             */
            sf::Clock _gameTimer;
            /**
             * @brief Store ellasped time
             *
             */
            sf::Time _ellapsedTime;
        public:
            /**
             * @brief Construct a new AEngine with an sfml window
             *
             * @param width
             * @param height
             * @param title
             * @param framerate
             * @param vSync
             */
            AEngine(unsigned int width, unsigned int height, const std::string &title, unsigned int framerate = 60, bool vSync = true);
            /**
             * @brief Destroy the AEngine
             *
             */
            virtual ~AEngine();
            /**
             * @brief Trigger at each event detected, return true if windows should quit
             *
             * @return true
             * @return false
             */
            virtual bool onEventTrigger(sf::Event &event) = 0;
            /**
             * @brief Draw object on window
             *
             */
            virtual void draw(sf::RenderWindow &window) = 0;
            /**
             * @brief Update game object...
             *
             * @param ellapsed
             */
            virtual void update(float ellapsedTime) = 0;
            /**
             * @brief Launch the engine
             *
             */
            void run(void);

    };

}
