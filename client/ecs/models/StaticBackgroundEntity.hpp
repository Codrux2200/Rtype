/*
** StaticBackgroundEntity.hpp for client in /home/saad/Rtype/client/ecs/models
**
** Made by Saad Berrada
** Login   <saad.berrada@epitech.eu>
**
** Started on  Tue Oct 31 16:45:47 2023 Saad Berrada
** Last update Tue Oct 31 16:45:47 2023 Saad Berrada
*/

#ifndef STATICBACKGROUNDENTITY_HPP_
# define STATICBACKGROUNDENTITY_HPP_
#include "Entity.hpp"
#include <string>

namespace ECS{
    /**
     * @brief Static Background Entity
     */
    class StaticBackgroundEntity : public Entity{
        public:
            /**
             * @brief Construct a new Static Background Entity object
             * 
             * @param path the path of the background
             */
            StaticBackgroundEntity(std::string path);
            ~StaticBackgroundEntity();

        protected:
        private:
    };
}

#endif /* !STATICBACKGROUNDENTITY_HPP_ */
