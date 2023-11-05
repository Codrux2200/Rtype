/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** ConvertPath
*/

#pragma once
#include <iostream>
#include <filesystem>

/**
 * @brief The path converter namespace
 */
namespace ConvertPath {
    /**
     * @brief Convert a path to a string
     *
     * @param path the path to convert
     * @return std::string the converted path
     */
    std::string convertPath(const std::string &path);
}
