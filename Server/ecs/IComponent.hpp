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
        /**
         * @brief Sprite component
         * 
        */
        SPRITE = 0,
        /**
         * @brief Hitbox component
         * 
        */
        HITBOX = 1,
        /**
         * @brief Sound component
         * 
        */
        SOUND = 2,
    };

    class IComponent {
        public:
            /**
             * @brief get the type of the component
             * 
             * @return ComponentType
             */
            virtual int getUid(void) const = 0;
            /**
             * @brief set the type of the component
             * 
             * @return ComponentType
             */
            virtual void setUid(int uid) = 0;
        protected:
        private:
    };
}

#endif /* !ICOMPONENT_HPP_ */
