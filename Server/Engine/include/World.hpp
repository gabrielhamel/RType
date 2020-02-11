/**
 * @file World.hpp
 * @author Gabriel Hamel (gabriel.hamel@epitech.eu)
 * @brief
 * @version 1.0
 * @date 2019-11-07
 *
 * @copyright Copyright (c) 2019
 *
 */

#pragma once

#include <memory>
#include <vector>
#include "Entity.hpp"
#include "System.hpp"
#include "NonCopyable.hpp"
#include "WorldHandler.hpp"
#include <boost/thread.hpp>

namespace rt::engine
{
    /**
     * @brief The world store all entities
     *
     */
    class World : public NonCopyable
    {
        private:
            /**
             * @brief Main mutex
             *
             */
            boost::mutex _mutex;
            /**
             * @brief THe world handler
             *
             */
            WorldHandler &_handler;
            /**
             * @brief The list of entity
             *
             */
            std::vector<std::unique_ptr<Entity>> _entity;
            /**
             * @brief The list of entity was killed
             *
             */
            std::vector<std::unique_ptr<Entity>> _entityKilled;
            /**
             * @brief Find entity in list specified
             *
             * @param list
             * @param entity
             * @return std::vector<std::unique_ptr<Entity>>::iterator
             */
            std::vector<std::unique_ptr<Entity>>::iterator findEntity(std::vector<std::unique_ptr<Entity>> &list, const Entity &entity);
            /**
             * @brief List of systems assigned to the world
             *
             */
            std::unordered_map<SystemType, std::shared_ptr<System>> _systems;
        public:
            /**
             * @brief Construct a new World object
             *
             */
            World(WorldHandler &handler);
            /**
             * @brief Destroy the World object
             *
             */
            ~World(void);
            /**
             * @brief Create a Entity object
             *
             * @return Entity&
             */
            Entity &createEntity(std::vector<std::reference_wrapper<rt::network::BoostUdpEndpoint>> endpoints);
            Entity &createEntity(const std::string &id, std::vector<std::reference_wrapper<rt::network::BoostUdpEndpoint>> endpoints);
            /**
             * @brief Kill entity and remove her from the world
             *
             * @param entity
             */
            void killEntity(Entity &entity);
            /**
             * @brief Add system to the world
             *
             * @tparam T
             * @tparam Args
             * @param args
             * @return T&
             */
            template <typename T>
            T &addSystem();
            System &addSystem(SystemType system);
            /**
             * @brief Remove an system
             *
             * @tparam T
             */
            template <typename T>
            void removeSystem(void);
            void removeSystem(SystemType system);
            /**
             * @brief Get the System object
             *
             * @tparam T
             * @return T&
             */
            template <typename T>
            T &getSystem(void);
            System &getSystem(SystemType system);
            /**
             * @brief Check if word has system
             *
             * @tparam T
             * @return true
             * @return false
             */
            template <typename T>
            bool hasSystem(void);
            bool hasSystem(SystemType system);
            /**
             * @brief Return all systems
             *
             * @return std::unordered_map<SystemType, std::shared_ptr<System>>
             */
            std::unordered_map<SystemType, std::shared_ptr<System>> getSystems(void);
            /**
             * @brief Refresh the world, delete all entieties killed ...
             *
             */
            void refresh(void);
            /**
             * @brief Get Handler
             *
             * @return WorldHandler&
             */
            WorldHandler &getHandler();
            /**
             * @brief Get Entity or create if not exist
             *
             * @param id
             * @return Entity&
             */
            Entity &getEntity(const std::string id, rt::network::BoostUdpEndpoint &endpoint);
            /**
             * @brief Just get entity
             *
             * @param id
             * @return Entity&
             */
            Entity &getEntity(const std::string id);
            /**
             * @brief Get Entities Return all entities
             *
             * @return std::vector<Entity>
             */
            std::vector<std::reference_wrapper<Entity>> getEntities(void);
    };

    template <typename T>
    T &World::addSystem()
    {
        static_assert(std::is_base_of<System, T>(), "That class doesn't inherit from system");
        if (hasSystem<T>())
            throw std::runtime_error("This system is already assigned to that world");
        _systems.emplace(getSystemType<T>(), std::make_shared<T>());
        _handler.onSystemAdded(getSystemType<T>());
        return getSystem<T>();
    }

    template <typename T>
    void World::removeSystem(void)
    {
        static_assert(std::is_base_of<System, T>(), "That class doesn't inherit from system");
        auto it = _systems.find(getSystemType<T>());
        if (it == _systems.end())
            throw std::runtime_error("There is not that system in that world");
        _handler.onSystemRemoved(getSystemType<T>());
        _systems.erase(it);
    }

    template <typename T>
    T &World::getSystem(void)
    {
        static_assert(std::is_base_of<System, T>(), "That class doesn't inherit from system");
        auto it = _systems.find(getSystemType<T>());
        if (it == _systems.end())
            throw std::runtime_error("There is not that system in that world");
        return static_cast<T &>(*it->second);
    }

    template <typename T>
    bool World::hasSystem(void)
    {
        static_assert(std::is_base_of<System, T>(), "That class doesn't inherit from system");
        return _systems.find(getSystemType<T>()) != _systems.end();
    }

}
