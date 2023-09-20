/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** IComponent
*/

#ifndef ICOMPONENT_HPP_
#define ICOMPONENT_HPP_

namespace ECS {
    /**
     * @brief ComponentType
     * 
     */
    enum ComponentType
    {
        SPRITE = 0,
        HITBOX = 1,
        SOUND = 2,
    };

    class IComponent {
        public:
            /**
             * @brief get the type of the component
             * 
             * @return ComponentType
             */
            virtual int getUid(void) = 0;
            /**
             * @brief set the type of the component
             * 
             * @return ComponentType
             */
            virtual void setUid(int uid) = 0;
        protected:
        private:
            /**
             * @brief define the type of the component
             * 
             */
            int _uid;
    };
}

#endif /* !ICOMPONENT_HPP_ */
