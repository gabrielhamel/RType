/**
 * @file Texture.hpp
 * @author Jeremy Groizard (jeremy.groizard@epitech)
 * @brief Texture Compoenent
 * @version 0.1
 * @date 2019-11-29
 *
 * @copyright Copyright (c) 2019
 *
 */

#pragma once

#include <string>
#include "Engine.hpp"
#include <SFML/Graphics.hpp>


namespace rt::game::components
{
	typedef struct {
		std::string path;
		std::vector<sf::Rect<int>> frames;
		float time;
	} frames_t;

	enum TextureType {
		VesselLvl1,
		VesselLvl2,
		VesselLvl3,
		VesselLvl4,
		VesselLvl5,
		PlayerBullet,
		EnemyBullet,
		EnemyCommon,
		EnemyRare,
		EnemyEpic,
		EnemyBoss,
	};


	class Texture : public rt::engine::Component
	{
		private:
			std::string _path;
			size_t _current;
			TextureType _type;
			float _clock;
		public:
			Texture(TextureType type);
			Texture(rt::Byte &packet);
			sf::Rect<int> getRect(void);
			void deserialize(rt::Byte packet);
			rt::Byte serialize(void) const;
			std::shared_ptr<sf::Texture> instance(void) const;
			sf::Rect<int> currentRect(void) const;
			void nextRect(float ellapsedTime);
			float animTime(void) const;
	};


}
