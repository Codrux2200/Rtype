/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** WindowManager
*/

#include "WindowManager.hpp"

WindowManager::WindowManager(const std::string& title, unsigned int width, unsigned height) : _modeSize(width, height), _window(sf::VideoMode(_modeSize, 32), title)
{
}

sf::RenderWindow &WindowManager::getWindow()
{
    return _window;
}
