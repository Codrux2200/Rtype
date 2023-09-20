/*
** EPITECH PROJECT, 2023
** RtypeExperimentation
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
            void init(SceneManager &SceneManager);
            /**
             * @brief update all the system
             * 
             * @param SceneManager 
             * @param deltaTime 
             */
            void Update(SceneManager &SceneManager, int deltaTime);
            /**
             * @brief destroy all the system
             * 
             * @param SceneManager 
             */
            void Destroy(SceneManager &SceneManager);
            /**
             * @brief init audio from a filepath and return true if ok
             * 
             * @param file 
             * @return true
             * @return false
             */
            bool InitAudio(std::string const &file);
            /**
             * @brief Set the volume at volume %
             * 
             * @param volume 
             */
            void SetVolume(float volume);
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
            float GetMainVolume();
        protected:
            float _Volume;
            std::string _filePath;
        private:
    };
}

#endif /* !AUDIOSYSTEM_HPP_ */
