/**
 * @file Drawable.cpp
 * @author Loïc Bontemps (loic1.bontemps@epitech.eu)
 * @brief
 * @version 1.0
 * @date 2019-12-01
 *
 * @copyright Copyright (c) 2019
 *
 */

#include "Drawable.hpp"

using namespace rt::game::components;

Drawable::Drawable() :
initialized(false)
{

}

Drawable::~Drawable()
{

}

Drawable::Drawable(rt::Byte &packet)
{

}

void Drawable::deserialize(rt::Byte packet)
{

}

rt::Byte Drawable::serialize(void) const
{
	rt::Byte packet;

	return packet;
}
