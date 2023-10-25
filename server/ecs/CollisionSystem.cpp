/*
** EPITECH PROJECT, 2023
** RType
** File description:
** CollisionSystem
*/

#include "CollisionSystem.hpp"
#include <memory>
#include "HitboxComponent.hpp"
#include "PositionComponent.hpp"

namespace ECS {
    CollisionSystem::CollisionSystem()
    {}

    void CollisionSystem::update(SceneManager &sceneManager, float deltaTime, std::vector<Network::Packet> &packetQueue)
    {
        for (auto entity : sceneManager.getCurrentScene()->entitiesList) {
            if (!entity->isEnabled)
                continue;
            std::shared_ptr<HitboxComponent> hitboxComponent = entity->getComponent<HitboxComponent>();
            std::shared_ptr<PositionComponent> positionComponent = entity->getComponent<PositionComponent>();

            if (hitboxComponent == nullptr || !hitboxComponent->isEnabled)
                continue;

            for (auto entity2 : sceneManager.getCurrentScene()->entitiesList) {
                if (!entity2->isEnabled)
                    continue;
                if (entity2 == entity)
                    continue;
                auto hitboxComponent2 = entity2->getComponent<HitboxComponent>();
                auto positionComponent2 = entity2->getComponent<PositionComponent>();

                if (hitboxComponent2 == nullptr)
                    continue;

                auto hitbox1 = hitboxComponent->getHitbox();
                auto hitbox2 = hitboxComponent2->getHitbox();

                if (!hitboxComponent2->isEnabled)
                    continue;

                auto pos1 = positionComponent->getValue();
                auto pos2 = positionComponent2->getValue();

                int x1 = pos1[0] + hitbox1[0].first;
                int x2 = pos1[0] + hitbox1[1].first;
                int y1 = pos1[1] + hitbox1[0].second;
                int y2 = pos1[1] + hitbox1[1].second;

                int _x1 = pos2[0] + hitbox2[0].first;
                int _x2 = pos2[0] + hitbox2[1].first;
                int _y1 = pos2[1] + hitbox2[0].second;
                int _y2 = pos2[1] + hitbox2[1].second;

                if ((_x1 > x1 && _x1 < x2 && _y1 > y1 && _y1 < y2) ||
                    (_x2 > x1 && _x2 < x2 && _y1 > y1 && _y1 < y2) ||
                    (_x1 > x1 && _x1 < x2 && _y2 > y1 && _y2 < y2) ||
                    (_x2 > x1 && _x2 < x2 && _y2 > y1 && _y2 < y2)) {
                    hitboxComponent->executeCallback(entity2, packetQueue);
                    hitboxComponent2->executeCallback(entity, packetQueue);
                }
            }
        }
    }
}