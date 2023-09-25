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
    class ParticleSystem : public ASystem{
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
        protected:
        private:
    };
}

#endif /* !PARTICLESYSTEM_HPP_ */
