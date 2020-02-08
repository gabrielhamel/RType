/**
 * @file Parallax.hpp
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

class Parallax
{

private:

    std::vector<std::unique_ptr<sf::Texture>> m_textures;

    std::vector<float> m_speeds;

    std::vector<std::pair<std::unique_ptr<sf::Sprite>, std::unique_ptr<sf::Sprite>>> m_sprites;

public:

    void addLayer(const std::string &file, float speed);

    void update(float ellaspedTime);

    void draw(sf::RenderWindow &window) const;

};
