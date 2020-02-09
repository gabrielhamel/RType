/**
 * @file Bullet.hpp
 * @author Gabriel Hamel (gabriel.hamel@epitech.eu)
 * @brief
 * @version 1.0
 * @date 2020-02-08
 *
 * @copyright Copyright (c) 2020
 *
 */

#pragma once

#include "AnimatedSprite.hpp"

class Bullet : public AnimatedSprite
{

private:

    float m_speed;

    bool m_isDead;

public:

    bool isCollide(const AnimatedSprite &entity) const;

    Bullet(const sf::Sprite &shooter, Engine &engine);

    void update(float ellapsedTime);

    bool isDead() const;

    void die();

};
