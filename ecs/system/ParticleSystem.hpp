/*
** EPITECH PROJECT, 2023
** RtypeExperimentation
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
             * @param SceneManager 
             */
            void init(SceneManager &SceneManager) override;
            /**
             * @brief update all the system
             * 
             * @param SceneManager 
             * @param deltaTime 
             */
            void Update(SceneManager &SceneManager, int deltaTime) override;
            /**
             * @brief destroy all the system
             * 
             * @param SceneManager 
             */
            void Destroy(SceneManager &SceneManager) override;
        protected:
        private:
    };
}

#endif /* !PARTICLESYSTEM_HPP_ */
