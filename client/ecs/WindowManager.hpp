/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** WindowManager
*/

#pragma once

#include <SFML/Graphics.hpp>
#include <string>

/**
 * @brief Window Manager
 */
class WindowManager {
    public:
        /**
         * @brief Construct a new Window Manager object
         *
         * @param title the title of the window
         * @param width the width of the window
         * @param height the height of the window
         */
        WindowManager(const std::string& title, unsigned int width, unsigned int height);
        /**
         * @brief Get the Window object
         * 
         * @return sf::RenderWindow& the window
         */
        sf::RenderWindow &getWindow();

    private:
        /**
         * @brief The size of the window
         */
        sf::Vector2u _modeSize;
        /**
         * @brief The window
         */
        sf::RenderWindow _window;
};
