/**
 * @file Player.hpp
 * @author Gabriel Hamel (gabriel.hamel@epitech.eu)
 * @brief
 * @version 1.0
 * @date 2020-02-08
 *
 * @copyright Copyright (c) 2020
 *
 */

#pragma once

#include <SFML/Graphics.hpp>

class Engine;

class Player : public sf::Sprite
{

private:

    Engine &m_engine;

    sf::Texture m_texture;

    float m_speedX;

    float m_speedY;

    bool m_shot;

    float m_bulletTime;

    void setTextureNo(unsigned int nb);

public:

    Player(Engine &engine);

    void update(float ellaspedTime);

    void setSpeedX(float x);

    void setSpeedY(float y);

    void setOnShot(bool enable);

    float getSpeedX() const;

    float getSpeedY() const;

};
