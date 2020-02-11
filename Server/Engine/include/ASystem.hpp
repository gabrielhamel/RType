/**
 * @file ASystem.hpp
 * @author Gabriel Hamel (gabriel.hamel@epitech.eu)
 * @brief Basic class for system
 * @version 1.0
 * @date 2019-11-20
 *
 * @copyright Copyright (c) 2019
 *
 */

#pragma once

#include "Entity.hpp"
#include "NonCopyable.hpp"
#include "SystemType.hpp"

namespace rt::engine
{
    using ComponentList = std::vector<ComponentType>;
    /**
     * @brief Command entity
     *
     */
    class ASystem : public NonCopyable
    {
        private:
            /**
             * @brief Entity list
             *
             */
            std::vector<std::unique_ptr<Entity>> _entities;
            /**
             * @brief The differents component would system need
             *
             */
            ComponentList _requires;
            /**
             * @brief The excludes component
             *
             */
            ComponentList _excludes;
            /**
             * @brief To find entity in _entities
             *
             * @param list
             * @param entity
             * @return std::vector<std::unique_ptr<Entity>>::iterator
             */
            std::vector<std::unique_ptr<Entity>>::const_iterator findEntity(const Entity &entity) const;
            /**
             * @brief The system type
             *
             */
            SystemType _type;
        public:
            /**
             * @brief Construct a new ASystem object
             *
             */
            ASystem(SystemType type, ComponentList requires, ComponentList excludes);
            /**
             * @brief Destroy the ASystem object
             *
             */
            virtual ~ASystem(void);
            /**
             * @brief Check if entity respect the system
             *
             * @param entity
             * @return true
             * @return false
             */
            bool isEntityApplicable(Entity &entity) const;
            /**
             * @brief Add entity to the system
             *
             * @param entity
             */
            void addEntity(Entity &entity);
            /**
             * @brief Remove an entity of the system
             *
             * @param entity
             */
            void removeEntity(Entity &entity);
            /**
             * @brief Check if system has entity
             *
             * @param entity
             * @return true
             * @return false
             */
            bool hasEntity(Entity &entity) const;
            /**
             * @brief Get all entity who's respect filters
             *
             * @return std::vector<std::reference_wrapper<Entity>>
             */
            std::vector<std::reference_wrapper<Entity>> getApplicableEntities(void) const;
        protected:
            /**
             * @brief Trigger on entity added. Can be override
             *
             */
            virtual void onEntityAdded(Entity &entity);
            /**
             * @brief Trigger on entity removed. Can be override
             *
             */
            virtual void onEntityRemoved(Entity &entity);
    };

}
