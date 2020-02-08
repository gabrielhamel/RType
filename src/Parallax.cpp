/**
 * @file Parallax.cpp
 * @author Gabriel Hamel (gabriel.hamel@epitech.eu)
 * @brief
 * @version 1.0
 * @date 2020-02-08
 *
 * @copyright Copyright (c) 2020
 *
 */

#include "Parallax.hpp"

void Parallax::addLayer(const std::string &file, float speed)
{
    this->m_textures.push_back(std::make_unique<sf::Texture>());
    const auto &texture = this->m_textures.end() - 1;
    (*texture)->loadFromFile(file);
    this->m_speeds.push_back(speed);
    this->m_sprites.push_back(std::make_pair(std::make_unique<sf::Sprite>(**texture), std::make_unique<sf::Sprite>(**texture)));
    const auto &sprites = *(this->m_sprites.end() - 1);
    sprites.first->setTexture(**texture);
    sprites.second->setTexture(**texture);
    sprites.first->setPosition(0, 0);
    sprites.second->setPosition((*texture)->getSize().x, 0);
}

static void checkContext(sf::Sprite &sprite)
{
    auto pos = sprite.getPosition().x;
    auto size = sprite.getTexture()->getSize().x;
    if (pos + size < 0)
        sprite.setPosition(size, 0);
}

void Parallax::update(float ellaspedTime)
{
    for (size_t i = 0; i < this->m_textures.size(); i++) {
        this->m_sprites[i].first->move(-1 * this->m_speeds[i] * ellaspedTime, 0);
        this->m_sprites[i].second->move(-1 * this->m_speeds[i] * ellaspedTime, 0);
        checkContext(*this->m_sprites[i].first);
        checkContext(*this->m_sprites[i].second);
    }
}

void Parallax::draw(sf::RenderWindow &window) const
{
    for (const auto &spritesSet : this->m_sprites) {
        window.draw(*spritesSet.first);
        window.draw(*spritesSet.second);
    }
}
