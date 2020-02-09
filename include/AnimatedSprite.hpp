/**
 * @file EnemySprites.hpp
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
#include <memory>

#include "Entities.hpp"

class Engine;

typedef struct {
    std::string path;
    std::vector<sf::Rect<int>> frames;
    float time;
    float defense;
} frames_t;

class AnimatedSprite : public sf::Sprite
{

protected:

    Engine &m_engine;

    Entity m_type;

    size_t m_current;

    float m_clock;

    sf::Texture m_texture;

    float m_life;

    sf::RectangleShape m_lifeBar;

public:

    bool isDead;

    float speedX;

    float speedY;

    AnimatedSprite(Entity entity, Engine &engine);

    virtual ~AnimatedSprite();

    virtual void update(float ellapsedTime);

    void draw(sf::RenderWindow &window);

    void moveX(float value);

    void moveY(float value);

    void takeDamage(float amount);

    Entity getType() const;

};
