/*
** EPITECH PROJECT, 2023
** RtypeExperimentation
** File description:
** entity
*/

#ifndef ENTITY_HPP_
#define ENTITY_HPP_
#include <Vector>
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
         * @brief Entity Id
         * 
         */
            int Id;
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


    };

}

#endif /* !ENTITY_HPP_ */

