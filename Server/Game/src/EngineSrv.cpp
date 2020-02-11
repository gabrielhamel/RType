/**
 * @file EngineSrv.cpp
 * @author Gabriel Hamel (gabriel.hamel@epitech.ey)
 * @brief
 * @version 1.0
 * @date 2019-11-20
 *
 * @copyright Copyright (c) 2019
 *
 */

#include "EngineSrv.hpp"
#include "Game.hpp"

using namespace rt::game::srv;
using namespace rt::game::components;
using namespace rt::game::systems;

EngineSrv::EngineSrv(rt::game::Game &game) :
_game(game), _world(game.getWorld()), _clockComponents(0)
{
    // Initialize components and systems
	rt::game::components::initComponents();
	rt::game::systems::initSystems();
    // DONT REMOVE
    _world.addSystem<ApplyMovement>();
    _world.addSystem<UpdateAnimation>();
    _world.addSystem<Draw>();
    _world.addSystem<DrawLife>();
    _world.addSystem<EntityKiller>();
}

EngineSrv::~EngineSrv(void)
{

}

void EngineSrv::playerShoot(rt::engine::Entity &shooter)
{
    auto &bullet = _world.createEntity(_game.getServer().getAllClients());

    auto &coord = shooter.getComponent<Position>();
    auto &size = shooter.getComponent<Size>();
    bullet.addComponent<Position>(coord.x + size.x + 5, coord.y + (size.y / 2));
    bullet.addComponent<Size>(10, 10);
    bullet.addComponent<Speed>(400, 0);
    bullet.addComponent<Texture>(TextureType::PlayerBullet);
    bullet.addComponent<Drawable>();

    _world.getSystem<ApplyMovement>().addEntity(bullet);
    _world.getSystem<UpdateAnimation>().addEntity(bullet);
    _world.getSystem<Draw>().addEntity(bullet);
    _world.getSystem<EntityKiller>().addEntity(bullet);

    bullet.activate();
}

void EngineSrv::enemyShoot(rt::engine::Entity &shooter)
{
    auto &bullet = _world.createEntity(_game.getServer().getAllClients());

    auto &coord = shooter.getComponent<Position>();
    auto &size = shooter.getComponent<Size>();
    bullet.addComponent<Position>(coord.x - 5, coord.y + (size.y / 2));
    bullet.addComponent<Size>(10, 10);
    bullet.addComponent<Speed>(-400, 0);
    bullet.addComponent<Texture>(TextureType::EnemyBullet);
    bullet.addComponent<Drawable>();

    _world.getSystem<ApplyMovement>().addEntity(bullet);
    _world.getSystem<UpdateAnimation>().addEntity(bullet);
    _world.getSystem<Draw>().addEntity(bullet);
    _world.getSystem<EntityKiller>().addEntity(bullet);

    bullet.activate();
}

void EngineSrv::addNewEnemy(rt::game::EnemyType enemy)
{
    auto &new_enemy = _world.createEntity(_game.getServer().getAllClients());

    switch (enemy) {
        case rt::game::EnemyType::Common:
            new_enemy.addComponent<Position>(700, rand() % 550);
            new_enemy.addComponent<Texture>(TextureType::EnemyCommon);
            new_enemy.addComponent<Enemy>(rt::game::EnemyType::Common);
            new_enemy.addComponent<Speed>(rand() % 20 - 40, rand() % 30 - 15);
            new_enemy.addComponent<Size>(24, 20);
            new_enemy.addComponent<Life>(2000 * rt::game::EnemyType::Common * rt::game::EnemyType::Common);
            new_enemy.addComponent<Drawable>();
            break;
        case rt::game::EnemyType::Rare:
            new_enemy.addComponent<Position>(700, rand() % 550);
            new_enemy.addComponent<Texture>(TextureType::EnemyRare);
            new_enemy.addComponent<Enemy>(rt::game::EnemyType::Rare);
            new_enemy.addComponent<Speed>(rand() % 20 - 40, rand() % 30 - 15);
            new_enemy.addComponent<Size>(33, 32);
            new_enemy.addComponent<Life>(2000 * rt::game::EnemyType::Rare * rt::game::EnemyType::Rare);
            new_enemy.addComponent<Drawable>();
            break;
        case rt::game::EnemyType::Epic:
            new_enemy.addComponent<Position>(700, rand() % 550);
            new_enemy.addComponent<Texture>(TextureType::EnemyEpic);
            new_enemy.addComponent<Enemy>(rt::game::EnemyType::Epic);
            new_enemy.addComponent<Speed>(rand() % 20 - 40, rand() % 30 - 15);
            new_enemy.addComponent<Size>(57, 56);
            new_enemy.addComponent<Life>(2000 * rt::game::EnemyType::Epic * rt::game::EnemyType::Epic);
            new_enemy.addComponent<Drawable>();
            break;
        case rt::game::EnemyType::Boss:
            new_enemy.addComponent<Position>(530, 200);
            new_enemy.addComponent<Texture>(TextureType::EnemyBoss);
            new_enemy.addComponent<Enemy>(rt::game::EnemyType::Boss);
            new_enemy.addComponent<Speed>(0, 0);
            new_enemy.addComponent<Size>(258, 142);
            new_enemy.addComponent<Life>(2000 * rt::game::EnemyType::Boss * rt::game::EnemyType::Boss);
            new_enemy.addComponent<Drawable>();
            break;
    }
    _world.getSystem<ApplyMovement>().addEntity(new_enemy);
    _world.getSystem<UpdateAnimation>().addEntity(new_enemy);
    _world.getSystem<Draw>().addEntity(new_enemy);
    _world.getSystem<DrawLife>().addEntity(new_enemy);
    _world.getSystem<EntityKiller>().addEntity(new_enemy);
    new_enemy.activate();
}

void EngineSrv::onNewConnection(void)
{
    auto &player = _world.createEntity(_game.getServer().getAllClients());
    auto &playComponent = player.addComponent<rt::game::components::Player>();

    player.addComponent<Position>(rand() % 750, rand() % 550);
    player.addComponent<Size>(33, 17);
    player.addComponent<Texture>((TextureType)(rand() % 5));
    player.addComponent<Speed>(0, 0);
    player.addComponent<Drawable>();
    player.addComponent<Life>();

    _world.getSystem<ApplyMovement>().addEntity(player);
    _world.getSystem<UpdateAnimation>().addEntity(player);
    _world.getSystem<Draw>().addEntity(player);
    _world.getSystem<DrawLife>().addEntity(player);
    _world.getSystem<EntityKiller>().addEntity(player);

    player.activate();
}

void EngineSrv::update(float ellapsedTime)
{
    _world.getSystem<ApplyMovement>().update(ellapsedTime);
    _world.getSystem<UpdateAnimation>().update(ellapsedTime);
    _world.getSystem<EntityKiller>().update();


    // Spawn monster
    _clockMonster += ellapsedTime;
    if (_clockMonster >= 10) {
        _clockMonster = 0;
        addNewEnemy(rt::game::EnemyType::Boss);
    }

    // Send tous les components toutes les ~0.2s
    _clockComponents += ellapsedTime;
    if (_clockComponents >= 0.2f) {
        _clockComponents = 0;
        auto entities = _world.getEntities();
        for (auto entity : entities) {
            if (entity.get().hasComponent<Player>())
                playerShoot(entity);
            auto components = entity.get().getComponents();
            for (auto component : components)
                entity.get().syncComponent(component);
        }
    }
}

void EngineSrv::onEntityCreated(rt::engine::Entity &entity)
{

}

void EngineSrv::onEntityKilled(rt::engine::Entity &entity)
{

}

void EngineSrv::onSystemAdded(rt::engine::SystemType system)
{

}

void EngineSrv::onSystemRemoved(rt::engine::SystemType system)
{

}

void EngineSrv::onEntityActivated(rt::engine::Entity &entity)
{

}

void EngineSrv::onEntityDesactivated(rt::engine::Entity &entity)
{

}

void EngineSrv::onEntityComponentAdded(rt::engine::Entity &entity, rt::engine::ComponentType component)
{

}

void EngineSrv::onEntityComponentUpdated(rt::engine::Entity &entity, rt::engine::ComponentType component)
{
    entity.syncComponent(component);
}

void EngineSrv::onEntityComponentRemoved(rt::engine::Entity &entity, rt::engine::ComponentType component)
{

}

void EngineSrv::onSystemEntityAdded(rt::engine::Entity &entity, rt::engine::SystemType system)
{

}

void EngineSrv::onSystemEntityRemoved(rt::engine::Entity &entity, rt::engine::SystemType system)
{

}

std::vector<std::reference_wrapper<rt::network::BoostUdpEndpoint>> EngineSrv::getAllConnections()
{
    return {};
}
