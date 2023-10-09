/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** AComponent
*/

#ifndef ACOMPONENT_HPP_
#define ACOMPONENT_HPP_
#include "IComponent.hpp"
#include <vector>

namespace ECS {
    /**
     * @brief AComponent class
     * 
     */
    class AComponent : public IComponent {
        public:
            /**
             * @brief Construct a new AComponent object
             * 
             * @param uid 
             */
            AComponent(int uid);
            /**
             * @brief Destroy the AComponent object
             * 
             */
            ~AComponent();
            /**
             * @brief Get the Uid object
             * 
             * @return the uid of the component
             */
            int getUid() const final;
            /**
             * @brief Set the Uid object
             * 
             * @param uid 
             */
            void setUid(int uid) final;
            /**
             * @brief Get the Value object
             * 
             * @return the value asked
             */
            virtual std::vector<int> getValue() const;
            /**
             * @brief Set the Value object
             * 
             * @param valueA
             * 
             * @param valueB
             */
            virtual void setValue(int valueA, int valueB);
        protected:
        private:
            /**
             * @brief UID of the component
             *  
             */
            int _uid;
    };
}

#endif /* !AComponent_HPP_ */
