/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** ButtonEntity
*/

#pragma once

#include "Entity.hpp"
#include <string>

namespace ECS {
    /**
     * @brief Button Entity
     */
    class ButtonEntity : public Entity {
        public:
            /**
             * @brief Construct a new Button Entity object
             *
             * @param path the path of the button
             * @param x the x position
             * @param y the y position
             */
            ButtonEntity(std::string path, int x, int y);
            ~ButtonEntity() = default;

    };
}
