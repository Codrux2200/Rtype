/*
** EPITECH PROJECT, 2023
** RtypeExperimentation
** File description:
** iSystem
*/

#ifndef ISYSTEM_HPP_
#define ISYSTEM_HPP_
#include "../SceneManager.hpp"

namespace ECS
{
    enum SystemType {
        GAME = 0,
        GRAPHIQUE = 1,
        EVENT = 2,
        PARTICLE = 3,
        COLLIDE = 4,
        AUDIO = 5,
        NETWORK = 6,
    };

    class ISystem {
        public :
            virtual void init(SceneManager &) = 0;
            virtual void Update(SceneManager &, int deltaTime) = 0;
            virtual void Destroy(SceneManager &) = 0;
    };
} // namespace ECS


#endif /* !ISYSTEM_HPP_ */
