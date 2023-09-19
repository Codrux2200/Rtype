/*
** EPITECH PROJECT, 2023
** RtypeExperimentation
** File description:
** IComponent
*/

#ifndef ICOMPONENT_HPP_
#define ICOMPONENT_HPP_

namespace ECS {

    enum Type
    {
        SPRITE = 0,
        HITBOX = 1,
        SOUND = 2,
    };

    class IComponent {
        public:
            IComponent();
        protected:
        private:
    };
}

#endif /* !ICOMPONENT_HPP_ */
