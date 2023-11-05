/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** WindowManager
*/

#pragma once

#include <SFML/Graphics.hpp>
#include <string>

class WindowManager {
    public:
        WindowManager(const std::string& title, unsigned int width, unsigned int height);
        sf::RenderWindow &getWindow();

    private:
        /**
         * @brief The size of the window
         */
        sf::Vector2u _modeSize;

        sf::RenderWindow _window;
};
