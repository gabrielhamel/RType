/**
 * @file Texture.cpp
 * @author Jeremy Groizard (jeremy.groizard@epitech)
 * @brief Texture Component implementation
 * @version 0.1
 * @date 2019-11-29
 *
 * @copyright Copyright (c) 2019
 *
 */

#include "Texture.hpp"

static const rt::game::components::frames_t frames[] =
{
	{ "Res/vessel.gif", std::vector<sf::Rect<int>>({
		sf::Rect<int>(0, 0, 33, 17),
		sf::Rect<int>(0, 17, 33, 17),
		sf::Rect<int>(0, 34, 33, 17),
		sf::Rect<int>(0, 51, 33, 17),
		sf::Rect<int>(0, 68, 33, 17),
	}), 0.5f },
	{"Res/vessel.gif", std::vector<sf::Rect<int>>({
		sf::Rect<int>(33, 0, 33, 17),
		sf::Rect<int>(33, 17, 33, 17),
		sf::Rect<int>(33, 34, 33, 17),
		sf::Rect<int>(33, 51, 33, 17),
		sf::Rect<int>(33, 68, 33, 17),
	}), 0.5f },
	{"Res/vessel.gif", std::vector<sf::Rect<int>>({
		sf::Rect<int>(66, 0, 33, 17),
		sf::Rect<int>(66, 17, 33, 17),
		sf::Rect<int>(66, 34, 33, 17),
		sf::Rect<int>(66, 51, 33, 17),
		sf::Rect<int>(66, 68, 33, 17),
	}), 0.5f },
	{"Res/vessel.gif", std::vector<sf::Rect<int>>({
		sf::Rect<int>(99, 0, 33, 17),
		sf::Rect<int>(99, 17, 33, 17),
		sf::Rect<int>(99, 34, 33, 17),
		sf::Rect<int>(99, 51, 33, 17),
		sf::Rect<int>(99, 68, 33, 17),
	}), 0.5f },
	{"Res/vessel.gif", std::vector<sf::Rect<int>>({
		sf::Rect<int>(132, 0, 33, 17),
		sf::Rect<int>(132, 17, 33, 17),
		sf::Rect<int>(132, 34, 33, 17),
		sf::Rect<int>(132, 51, 33, 17),
		sf::Rect<int>(132, 68, 33, 17),
	}), 0.5f },
	{"Res/PlayerBullet.gif", std::vector<sf::Rect<int>>({
		sf::Rect<int>(0, 0, 32, 14),
		sf::Rect<int>(32, 0, 32, 14),
	}), 0.25f },
		{"Res/EnemyBullet.gif", std::vector<sf::Rect<int>>({
		sf::Rect<int>(0, 0, 32, 14),
		sf::Rect<int>(32, 0, 32, 14),
	}), 0.25f },
	{"Res/EnemyCommon.gif", std::vector<sf::Rect<int>>({
		sf::Rect<int>(86, 66, 24, 20),
	}), 0.5f },
	{"Res/EnemyRare.gif", std::vector<sf::Rect<int>>({
		sf::Rect<int>(0, 0, 33, 32),
		sf::Rect<int>(33, 0, 33, 32),
		sf::Rect<int>(66, 0, 33, 32),
		sf::Rect<int>(99, 0, 33, 32),
		sf::Rect<int>(132, 0, 33, 32),
		sf::Rect<int>(165, 0, 33, 32),
		sf::Rect<int>(198, 0, 33, 32),
		sf::Rect<int>(231, 0, 33, 32),
		sf::Rect<int>(0, 32, 33, 32),
		sf::Rect<int>(33, 32, 33, 32),
		sf::Rect<int>(66, 32, 33, 32),
		sf::Rect<int>(99, 32, 33, 32),
		sf::Rect<int>(132, 32, 33, 32),
		sf::Rect<int>(165, 32, 33, 32),
		sf::Rect<int>(198, 32, 33, 32),
		sf::Rect<int>(231, 32, 33, 32),
	}), 0.5f },
	{"Res/EnemyEpic.gif", std::vector<sf::Rect<int>>({
		sf::Rect<int>(0, 0, 57, 56),
		sf::Rect<int>(57, 0, 57, 56),
		sf::Rect<int>(114, 0, 57, 56),
		sf::Rect<int>(171, 0, 57, 56),
		sf::Rect<int>(228, 0, 57, 56),
	}), 0.2f },
	{"Res/EnemyBoss.gif", std::vector<sf::Rect<int>>({
		sf::Rect<int>(258, 0, 258, 142),
		sf::Rect<int>(0, 0, 258, 142),
		sf::Rect<int>(258, 142, 258, 142),
		sf::Rect<int>(0, 142, 258, 142),
		sf::Rect<int>(258, 284, 258, 142),
		sf::Rect<int>(0, 284, 258, 142),
		sf::Rect<int>(258, 426, 258, 142),
		sf::Rect<int>(0, 426, 258, 142),
	}), 0.2f },
};

namespace rt::game::components
{

	sf::Rect<int> Texture::getRect(void)
	{
		return frames[_type].frames[_current];
	}

	Texture::Texture(TextureType type) : _current(0), _clock(0)
	{
		_type = type;
		_path = frames[type].path;
	}

	Texture::Texture(rt::Byte &packet)
	{
		deserialize(packet);
	}

	void Texture::deserialize(rt::Byte packet)
	{
		_type = static_cast<TextureType>(static_cast<int>(packet));
		_path = static_cast<std::string>(packet);
		_current = static_cast<size_t>(packet);
	}

	rt::Byte Texture::serialize(void) const
	{
		rt::Byte packet;
		packet << _type;
		packet << _path;
		packet << _current;
		return packet;
	}

	std::shared_ptr<sf::Texture> Texture::instance(void) const
	{
		auto texture = std::make_shared<sf::Texture>();
		texture->loadFromFile(frames[_type].path);
		return texture;
	}

	sf::Rect<int> Texture::currentRect(void) const
	{
		return frames[_type].frames[_current];
	}

	void Texture::nextRect(float ellapsedTime)
	{
		_clock += ellapsedTime;
		if (_clock >= frames[_type].time) {
			_current = (_current + 1) % frames[_type].frames.size();
			_clock = 0;
		}
	}

	float Texture::animTime(void) const
	{
		return frames[_type].time;
	}


}
