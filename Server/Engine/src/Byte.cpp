/**
 * @file Byte.cpp
 * @author Gabriel Hamel (gabriel.hamel@epitech.eu)
 * @brief Implementation of Byte.hpp
 * @version 1.0
 * @date 2019-11-27
 *
 * @copyright Copyright (c) 2019
 *
 */

#include <memory>
#include <iostream>
#include "Byte.hpp"

using namespace rt;

Byte::Byte()
{

}

Byte::~Byte()
{

}

Byte &Byte::operator<<(int data)
{
    uint8_t *raw = reinterpret_cast<uint8_t *>(&data);
    for (size_t i = 0; i < sizeof(data); i++)
        _data.push_back(*static_cast<uint8_t *>(raw + i));
    return *this;
}

Byte &Byte::operator<<(uint8_t data)
{
    uint8_t *raw = reinterpret_cast<uint8_t *>(&data);
    for (size_t i = 0; i < sizeof(data); i++)
        _data.push_back(*static_cast<uint8_t *>(raw + i));
    return *this;
}

Byte &Byte::operator<<(uint16_t data)
{
    uint8_t *raw = reinterpret_cast<uint8_t *>(&data);
    for (size_t i = 0; i < sizeof(data); i++)
        _data.push_back(*static_cast<uint8_t *>(raw + i));
    return *this;
}

Byte &Byte::operator<<(uint32_t data)
{
    uint8_t *raw = reinterpret_cast<uint8_t *>(&data);
    for (size_t i = 0; i < sizeof(data); i++)
        _data.push_back(*static_cast<uint8_t *>(raw + i));
    return *this;
}

Byte &Byte::operator<<(float data)
{
    uint8_t *raw = reinterpret_cast<uint8_t *>(&data);
    for (size_t i = 0; i < sizeof(data); i++)
        _data.push_back(*static_cast<uint8_t *>(raw + i));
    return *this;
}

Byte &Byte::operator<<(uint64_t data)
{
    uint8_t *raw = reinterpret_cast<uint8_t *>(&data);
    for (size_t i = 0; i < sizeof(data); i++)
        _data.push_back(*static_cast<uint8_t *>(raw + i));
    return *this;
}

Byte &Byte::operator<<(const std::string &data)
{
    uint8_t *raw = (uint8_t *)data.c_str();
    for (size_t i = 0; i < data.size() + 1; i++)
        _data.push_back(*static_cast<uint8_t *>(raw + i));
    return *this;
}

std::vector<uint8_t> Byte::getData(void) const
{
    return _data;
}

Byte::operator int()
{
    int number = 0;
    uint8_t *raw = reinterpret_cast<uint8_t *>(&number);
    auto data = getData();
    size_t i;
    for (i = 0; i < sizeof(number); i++)
        *(raw + i) = data[i];
    _data = std::vector<uint8_t>(_data.begin() + i, _data.end());
    return number;
}

Byte::operator uint8_t()
{
    uint8_t number = 0;
    uint8_t *raw = reinterpret_cast<uint8_t *>(&number);
    auto data = getData();
    size_t i;
    for (i = 0; i < sizeof(number); i++)
        *(raw + i) = data[i];
    _data = std::vector<uint8_t>(_data.begin() + i, _data.end());
    return number;
}

Byte::operator uint16_t()
{
    uint16_t number = 0;
    uint8_t *raw = reinterpret_cast<uint8_t *>(&number);
    auto data = getData();
    size_t i;
    for (i = 0; i < sizeof(number); i++)
        *(raw + i) = data[i];
    _data = std::vector<uint8_t>(_data.begin() + i, _data.end());
    return number;
}

Byte::operator float()
{
    float number = 0;
    uint8_t *raw = reinterpret_cast<uint8_t *>(&number);
    auto data = getData();
    size_t i;
    for (i = 0; i < sizeof(number); i++)
        *(raw + i) = data[i];
    _data = std::vector<uint8_t>(_data.begin() + i, _data.end());
    return number;
}

Byte::operator uint32_t()
{
    uint32_t number = 0;
    uint8_t *raw = reinterpret_cast<uint8_t *>(&number);
    auto data = getData();
    size_t i;
    for (i = 0; i < sizeof(number); i++)
        *(raw + i) = data[i];
    _data = std::vector<uint8_t>(_data.begin() + i, _data.end());
    return number;
}

Byte::operator uint64_t()
{
    uint64_t number = 0;
    uint8_t *raw = reinterpret_cast<uint8_t *>(&number);
    auto data = getData();
    size_t i;
    for (i = 0; i < sizeof(number); i++)
        *(raw + i) = data[i];
    _data = std::vector<uint8_t>(_data.begin() + i, _data.end());
    return number;
}

Byte::operator std::string()
{
    std::string str;
    auto data = getData();

    size_t i;
    for (i = 0; data[i] != 0; i++)
        str += (char)data[i];
    _data = std::vector<uint8_t>(_data.begin() + i + 1, _data.end());
    return str;
}

Byte::Byte(const Byte &copy)
{
    _data = copy._data;
}

Byte &Byte::operator=(const Byte &copy)
{
    _data = copy._data;
    return *this;
}

Byte &Byte::operator+=(const Byte &packet)
{
    auto vector = packet.getData();
    _data.insert(_data.end(), vector.begin(), vector.end());
    return *this;
}
