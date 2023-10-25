/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** ConvertPath
*/

#include <filesystem>
#include <iostream>
#include "ConvertPath.hpp"

RType::ConvertPath::ConvertPath(void)
{
}

std::string RType::ConvertPath::convertPath(const std::string &path)
{
    #ifdef _WIN32
        std::string newPath = path;
        for (int i = 0; i < newPath.size(); ++i)
            if (newPath[i] == '/')
                newPath[i] = '\\';
        return newPath;
    #else
        return path;
    #endif
}