/**
 * @file Entities.cpp
 * @author Gabriel Hamel (gabriel.hamel@epitech.eu)
 * @brief
 * @version 1.0
 * @date 2020-02-08
 *
 * @copyright Copyright (c) 2020
 *
 */

#include <iostream>

#include "AnimatedSprite.hpp"

static const frames_t entities[] =
{
    {"assets/PlayerBullet.gif", {
        {0, 0, 32, 14},
        {32, 0, 32, 14},
    }, 0.15f },
    {"assets/EnemyBullet.gif", {
        {0, 0, 32, 14},
        {32, 0, 32, 14},
    }, 0.25f },
    {"assets/EnemyCommon.gif", {
        {86, 66, 24, 20},
    }, 0.5f },
    {"assets/EnemyRare.gif", {
        {0, 0, 33, 32},
        {33, 0, 33, 32},
        {66, 0, 33, 32},
        {99, 0, 33, 32},
        {132, 0, 33, 32},
        {165, 0, 33, 32},
        {198, 0, 33, 32},
        {231, 0, 33, 32},
        {0, 32, 33, 32},
        {33, 32, 33, 32},
        {66, 32, 33, 32},
        {99, 32, 33, 32},
        {132, 32, 33, 32},
        {165, 32, 33, 32},
        {198, 32, 33, 32},
        {231, 32, 33, 32},
    }, 0.1f },
    {"assets/EnemyEpic.gif", {
        {0, 0, 57, 56},
        {57, 0, 57, 56},
        {114, 0, 57, 56},
        {171, 0, 57, 56},
        {228, 0, 57, 56},
    }, 0.2f },
    {"assets/EnemyBoss.gif", {
        {258, 0, 258, 142},
        {0, 0, 258, 142},
        {258, 142, 258, 142},
        {0, 142, 258, 142},
        {258, 284, 258, 142},
        {0, 284, 258, 142},
        {258, 426, 258, 142},
        {0, 426, 258, 142},
    }, 0.2f }
};

static const frames_t &getEntity(Entity entity)
{
    return entities[entity];
}

Entities::Entities()
{
    for (size_t i = 0; i < EntitySize; i++)
        this->m_textures[i].loadFromFile(getEntity((Entity)i).path);
}

const Entities &Entities::instance()
{
    static Entities *entities = new Entities();
    return *entities;
}

const sf::Texture &Entities::getTexture(Entity entity) const
{
    return this->m_textures[entity];
}

const std::vector<sf::IntRect> &Entities::getRects(Entity entity) const
{
    return getEntity(entity).frames;
}

float Entities::getFrameTime(Entity entity) const
{
    return getEntity(entity).time;
}
