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
    class AudioSystem : public ISystem{
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
             * @brief init Scene Manager
             * 
             * @param SceneManager 
             */
            void init(SceneManager &SceneManager) override;
            /**
             * @brief update all the system
             * 
             * @param SceneManager 
             * @param deltaTime 
             */
            void update(SceneManager &SceneManager, int deltaTime) override;
            /**
             * @brief destroy all the system
             * 
             * @param SceneManager 
             */
            void destroy(SceneManager &SceneManager) override;
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
            float _Volume;
            /**
             * @brief the filepath of the audio
             * 
             */
            std::string _filePath;
        private:
    };
}

#endif /* !AUDIOSYSTEM_HPP_ */
