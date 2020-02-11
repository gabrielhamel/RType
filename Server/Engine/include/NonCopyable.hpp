/**
 * @file NonCopyable.hpp
 * @author Gabriel Hamel (gabriel.hamel@epitech.eu)
 * @brief
 * @version 1.0
 * @date 2019-11-07
 *
 * @copyright Copyright (c) 2019
 *
 */

#pragma once

namespace rt
{
    /**
     * @brief Implement that class to prevent from object copy
     *
     */
    class NonCopyable
    {
        protected:
            /**
             * @brief Construct a new Non Copyable object
             *
             */
            NonCopyable(void) {}
            /**
             * @brief Destroy the Non Copyable object
             *
             */
            ~NonCopyable(void) {}
        private:
            /**
             * @brief Avoid to use copy constructor
             *
             */
            NonCopyable(NonCopyable const &);
            /**
             * @brief Avoid to use = operator
             *
             * @return NonCopyable&
             */
            NonCopyable &operator=(NonCopyable const &);
    };

}
