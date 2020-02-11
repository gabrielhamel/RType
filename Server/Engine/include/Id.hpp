/**
 * @file Id.hpp
 * @author Gabriel Hamel (gabriel.hamel@epitech.eu)
 * @brief
 * @version 1.0
 * @date 2019-11-07
 *
 * @copyright Copyright (c) 2019
 *
 */

#pragma once

#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <iostream>
#include "NonCopyable.hpp"

namespace rt::engine
{
    /**
     * @brief Class who create unique id
     *
     */
    class Id : public NonCopyable
    {
        private:
            /**
             * @brief The boost id
             *
             */
            boost::uuids::uuid _id;
            /**
             * @brief status is changed
             *
             */
            bool _changed;
            /**
             * @brief The attribued id
             *
             */
            std::string _newId;
        public:
            /**
             * @brief Construct a new Id object
             *
             */
            Id(void);
            /**
             * @brief Destroy the Id object
             *
             */
            ~Id(void);
            /**
             * @brief Compare if to id are equal
             *
             * @param to_compare
             * @return true
             * @return false
             */
            bool operator==(Id const &to_compare) const;
            /**
             * @brief Compare if to id aren't equal
             *
             * @param to_compare
             * @return true
             * @return false
             */
            bool operator!=(Id const &to_compare) const;
            /**
             * @brief Id to str
             *
             * @return std::string
             */
            std::string to_string(void) const;
            /**
             * @brief Change id
             *
             * @param id
             */
            void set(const std::string &id);
    };

    std::ostream &operator<<(std::ostream &out, const Id &to_convert);
}
