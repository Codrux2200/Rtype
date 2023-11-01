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

    void CollisionSystem::update(SceneManager &sceneManager, float deltaTime, std::vector<Network::Packet> &packetQueue)
    {
        for (const auto& entity : sceneManager.getCurrentScene()->entitiesList) {
            if (entity == nullptr || !entity->isEnabled)
                continue;

            std::vector<std::shared_ptr<HitboxComponent>> hitboxComponents = entity->getComponents<HitboxComponent>();

            std::shared_ptr<PositionComponent> positionComponent = entity->getComponent<PositionComponent>();

            if (positionComponent == nullptr || !positionComponent->isEnabled)
                continue;

            for (const auto& hitboxComponent : hitboxComponents) {

                if (hitboxComponent == nullptr || !hitboxComponent->isEnabled)
                    continue;

                for (const auto& entity2 : sceneManager.getCurrentScene()->entitiesList) {
                    if (entity2 == nullptr || !entity2->isEnabled || entity2 == entity)
                        continue;
                    auto hitboxComponents2 = entity2->getComponents<HitboxComponent>();
                    auto positionComponent2 = entity2->getComponent<PositionComponent>();

                    if (positionComponent2 == nullptr || !positionComponent2->isEnabled)
                        continue;

                    for (const auto &hitboxComponent2 : hitboxComponents2) {
                        if (hitboxComponent2 == nullptr || !hitboxComponent2->isEnabled)
                            continue;

                        auto hitbox1 = hitboxComponent->getHitbox();
                        auto hitbox2 = hitboxComponent2->getHitbox();

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

                        if ((_x1 > x1 && _x1 < x2 && _y1 > y1 && _y1 < y2)
                        || (_x2 > x1 && _x2 < x2 && _y1 > y1 && _y1 < y2)
                        || (_x1 > x1 && _x1 < x2 && _y2 > y1 && _y2 < y2)
                        || (_x2 > x1 && _x2 < x2 && _y2 > y1 && _y2 < y2)) {
                            hitboxComponent->executeCallback(entity, entity2, packetQueue);
                            hitboxComponent2->executeCallback(entity2, entity, packetQueue);
                        }
                    }
                }
            }
        }
    }
}