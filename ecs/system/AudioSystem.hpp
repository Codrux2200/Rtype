/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** AudioSystem
*/

#ifndef AUDIOSYSTEM_HPP_
#define AUDIOSYSTEM_HPP_
#include "ISystem.hpp"
#include <string>

namespace ECS {
    /**
     * @brief Audio System
     *
     */
    class AudioSystem : public ISystem {
        public:
            /**
             * @brief Construct a new Audio System object
             *
             */
            AudioSystem();
            /**
             * @brief Destroy the Audio System object
             *
             */
            ~AudioSystem();
            /**
             * @brief init audio from a filepath and return true if ok
             *
             * @param file
             * @return true
             * @return false
             */
            bool initAudio(std::string const &file);
            /**
             * @brief Set the volume at volume %
             *
             * @param volume
             */
            void setVolume(float volume);
            /**
             * @brief return true if it's ready to play
             *
             * @return true
             * @return false
             */
            bool isReady();
            /**
             * @brief Get the Main Volume object
             *
             * @return float
             */
            float getMainVolume();
        protected:
            /**
             * @brief the volume of the audio
             *
             */
            float _volume;
            /**
             * @brief the filepath of the audio
             *
             */
            std::string _filePath;
        private:
    };
}

#endif /* !AUDIOSYSTEM_HPP_ */
