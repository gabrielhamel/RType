/**
 * @file Id.cpp
 * @author Gabriel Hamel (gabriel.hamel@epitech.eu)
 * @brief
 * @version 1.0
 * @date 2019-11-07
 *
 * @copyright Copyright (c) 2019
 *
 */

#include <boost/uuid/uuid_generators.hpp>
#include "Id.hpp"

static boost::uuids::random_generator generator;

using namespace rt::engine;

bool Id::operator==(Id const &to_compare) const
{
    return _id == to_compare._id;
}

bool Id::operator!=(Id const &to_compare) const
{
    return !operator==(to_compare);
}

Id::Id(void) :
_id(generator()), _changed(false)
{

}

Id::~Id(void)
{

}

std::string Id::to_string(void) const
{
    if (_changed)
        return _newId;
    return boost::uuids::to_string(_id);
}

std::ostream &rt::engine::operator<<(std::ostream &out, const Id &to_convert)
{
    out << to_convert.to_string();
    return out;
}

void Id::set(const std::string &id)
{
    _changed = true;
    _newId = id;
}
