/*
** EPITECH PROJECT, 2023
** RtypeExperimentation
** File description:
** entity
*/

#ifndef ENTITY_HPP_
#define ENTITY_HPP_
#include <vector>
#include "IComponent.hpp"

namespace ECS {

    enum Tag{
        MOVABLE = 0,
        AUDIBLE = 1,
        DESTROYABLE = 2,
        COLIDLE = 3,
    };

    class Entity {
        public:
            /**
             * @brief Construct a new Entity object
             * 
             * @param id 
             */
            Entity(int id);
            /**
             * @brief Destroy the Entity object
             * 
             */
            ~Entity();
            /**
             * @brief stock component
             * 
             */
            std::vector<IComponent> Components;
        private :
            /**
             * @brief define the tag for the entity
             * 
             */
            std::vector<Tag> _Tags;
            /**
             * @brief define the id of the entity
             * 
             */
            int _id;

    };

}

#endif /* !ENTITY_HPP_ */

