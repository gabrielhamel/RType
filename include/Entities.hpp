/**
 * @file Enemies.hpp
 * @author Gabriel Hamel (gabriel.hamel@epitech.eu)
 * @brief
 * @version 1.0
 * @date 2020-02-08
 *
 * @copyright Copyright (c) 2020
 *
 */

#pragma once

enum Entity
{
    PlayerBullet,
    EnemyBullet,
    EnemyCommon,
    EnemyRare,
    EnemyEpic,
    EnemyBoss,
    EntitySize // At the end
};

class Entities
{

private:

    std::array<sf::Texture, EntitySize> m_textures;

public:

    Entities();

    static const Entities &instance();

    const sf::Texture &getTexture(Entity entity) const;

    const std::vector<sf::IntRect> &getRects(Entity entity) const;

    float getFrameTime(Entity entity) const;

    float getDefense(Entity entity) const;

};
