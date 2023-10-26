/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** ConvertPath
*/

#include <filesystem>
#include "ConvertPath.hpp"

std::string ConvertPath::convertPath(const std::string &path)
{
    #ifdef _WIN32
        std::string newPath = path;
        std::filesystem::path p(path);
        newPath = std::filesystem::absolute(p).string();
        return newPath;
    #else
        return path;
    #endif
}