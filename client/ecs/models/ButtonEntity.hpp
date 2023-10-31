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
    class ButtonEntity : public Entity {
        public:
            ButtonEntity(std::string path, int x, int y);
            ~ButtonEntity() = default;

    };
}
