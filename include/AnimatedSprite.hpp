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

typedef struct {
    std::string path;
    std::vector<sf::Rect<int>> frames;
    float time;
} frames_t;

class AnimatedSprite : public sf::Sprite
{

protected:

    Entity m_type;

    size_t m_current;

    float m_clock;

    sf::Texture m_texture;

public:

    AnimatedSprite(Entity entity);

    virtual ~AnimatedSprite();

    virtual void update(float ellapsedTime);

};
