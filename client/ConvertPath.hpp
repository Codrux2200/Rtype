/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** ConvertPath
*/

#pragma once
#include <iostream>
#include <filesystem>

namespace RType {
    class ConvertPath {
        public:
            ConvertPath(void);
            ~ConvertPath() = default;

            static std::string convertPath(const std::string &path);
        private:
    };
}
