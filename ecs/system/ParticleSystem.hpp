/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** ParticleSystem
*/

#ifndef PARTICLESYSTEM_HPP_
#define PARTICLESYSTEM_HPP_
#include "ISystem.hpp"

namespace ECS {
    /**
     * @brief Particle System
     * 
     */
    class ParticleSystem : public ISystem{
        public:
            /**
             * @brief Construct a new Particle System object
             * 
             */
            ParticleSystem();
            /**
             * @brief Destroy the Particle System object
             * 
             */
            ~ParticleSystem();
             /**
             * @brief init Scene Manager
             * 
             * @param sceneManager 
             */
            void init(SceneManager &sceneManager) override;
            /**
             * @brief update all the system
             * 
             * @param sceneManager 
             * @param deltaTime 
             */
            void update(SceneManager &sceneManager, int deltaTime) override;
            /**
             * @brief destroy all the system
             * 
             * @param sceneManager 
             */
            void destroy(SceneManager &sceneManager) override;
        protected:
        private:
    };
}

#endif /* !PARTICLESYSTEM_HPP_ */
