/**
 * @file Entity.hpp
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
#include <unordered_map>
#include "Id.hpp"
#include "NonCopyable.hpp"
#include "Component.hpp"
#include "Commands.hpp"
#include "NetworkPack.hpp"
#include "BoostUdp.hpp"

namespace rt::engine
{
    class World;
    /**
     * @brief Is the main object of the world
     *
     */
    class Entity : public NonCopyable
    {
        private:
            /**
             * @brief To send a packet at all member
             *
             * @param packet
             */
            void sendBroadcast(rt::Byte packet);
            /**
             * @brief The parent world
             *
             */
            World &_world;
            /**
             * @brief Map of component
             *
             */
            std::unordered_map<ComponentType, std::shared_ptr<Component>> _components;
            /**
             * @brief Entity was activated ?
             *
             */
            bool _activated;
            /**
             * @brief Entity was killed ?
             *
             */
            bool _killed;
            /**
             * @brief Trigger when component added
             *
             * @param component
             */
            void onComponentAdded(ComponentType component);
            /**
             * @brief Trigger when component removed
             *
             * @param component
             */
            void onComponentRemoved(ComponentType component);
            /**
             * @brief Trigger when component updated
             *
             * @param component
             */
            void onComponentUpdated(ComponentType component);
            /**
             * @brief All endpoint to syncro
             *
             */
            std::vector<std::reference_wrapper<rt::network::BoostUdpEndpoint>> _endpoints;
        public:
            /**
             * @brief Construct a new Entity object
             *
             */
            Entity(World &world);
            Entity(World &world, std::vector<std::reference_wrapper<rt::network::BoostUdpEndpoint>> endpoints);
            Entity(World &world, const std::string &id, std::vector<std::reference_wrapper<rt::network::BoostUdpEndpoint>> endpoints);
            /**
             * @brief Destroy the Entity object
             *
             */
            ~Entity(void);
            /**
             * @brief Get the World object
             *
             * @return World&
             */
            World &getWorld(void) const;
            /**
             * @brief Check if entity are the same
             *
             * @param entity
             * @return true
             * @return false
             */
            bool operator==(const Entity &entity) const;
            /**
             * @brief Check if entity aren't the same
             *
             * @param entity
             * @return true
             * @return false
             */
            bool operator!=(const Entity &entity) const;
            /**
             * @brief Activate the entity
             *
             * @param entity
             */
            void activate(void);
            /**
             * @brief Disactivate the entity
             *
             * @param entity
             */
            void desactivate(void);
            /**
             * @brief Check if entity is activated
             *
             * @param entity
             */
            bool isActivated(void) const;
            /**
             * @brief Kill entity and remove her from the world
             *
             * @param entity
             */
            void kill(void);
            /**
             * @brief To say if entity was killed
             *
             * @return true
             * @return false
             */
            bool isKilled(void);
            /**
             * @brief Add new component of type T and take the args in argument
             *
             * @tparam T
             * @tparam Args
             * @param args
             * @return T&
             */
            template <typename T, typename... Args>
            T &addComponent(Args &&... args);
            /**
             * @brief Same but no T
             *
             * @tparam Args
             * @param component
             * @param args
             * @return Component&
             */
            Component &addComponent(ComponentType component, rt::Byte packet);
            /**
             * @brief Remove component T
             *
             * @tparam T
             */
            template <typename T>
            void removeComponent(void);
            void removeComponent(ComponentType component);
            /**
             * @brief Get the Component T
             *
             * @tparam T
             * @return T&
             */
            template <typename T>
            T &getComponent(void) const;
            Component &getComponent(ComponentType component) const;

            /**
             * @brief Check if entity has the component T
             *
             * @tparam T
             * @return true
             * @return false
             */
            template <typename T>
            bool hasComponent(void) const;
            bool hasComponent(ComponentType component) const;
            /**
             * @brief The id of entity
             *
             */
            Id id;
            /**
             * @brief Return all endpoints connected
             *
             */
            std::vector<std::reference_wrapper<rt::network::BoostUdpEndpoint>> &endpoints(void) { return _endpoints; }
            /**
             * @brief Send data to all endpoints of component
             *
             */
            template <typename T>
            void syncComponent(void);
            void syncComponent(ComponentType component);
            /**
             * @brief Return all components
             *
             */
            std::vector<ComponentType> getComponents(void) const;
    };

    template <typename T, typename... Args>
    T &Entity::addComponent(Args &&... args)
    {
        static_assert(std::is_base_of<Component, T>(), "That class doesn't inherit from component");
        if (hasComponent<T>())
            throw std::runtime_error("This component is already assigned to that entity");
        _components.emplace(getComponentType<T>(), std::make_shared<T>(std::forward<Args>(args)...));
        onComponentAdded(getComponentType<T>());
        return getComponent<T>();
    }

    template <typename T>
    void Entity::removeComponent(void)
    {
        static_assert(std::is_base_of<Component, T>(), "That class doesn't inherit from component");
        if (this->_killed) return;
        auto it = _components.find(getComponentType<T>());
        if (it == _components.end())
            throw std::runtime_error("There is not that component in that entity");
        onComponentRemoved(getComponentType<T>());
        _components.erase(it);
    }

    template <typename T>
    T &Entity::getComponent(void) const
    {
        static_assert(std::is_base_of<Component, T>(), "That class doesn't inherit from component");
        auto it = _components.find(getComponentType<T>());
        if (it == _components.end())
            throw std::runtime_error("There is not that component in that entity");
        return static_cast<T &>(*it->second);
    }

    template <typename T>
    bool Entity::hasComponent(void) const
    {
        static_assert(std::is_base_of<Component, T>(), "That class doesn't inherit from component");
        if (this->_killed) return false;
        return _components.find(getComponentType<T>()) != _components.end();
    }

    template <typename T>
    void Entity::syncComponent(void)
    {
        static_assert(std::is_base_of<Component, T>(), "That class doesn't inherit from component");
        if (this->_killed) return;
        auto it = _components.find(getComponentType<T>());
        if (it == _components.end())
            throw std::runtime_error("There is not that component in that entity");
        rt::Byte cmd;
        cmd << rt::engine::TypeCmd::EntityComponentUpdated;
        rt::engine::ComponentType type = rt::engine::getComponentType<T>();
        cmd += rt::network::pack(*this, type);
        sendBroadcast(cmd);
    }

}
