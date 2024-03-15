/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 13:36:17 by achabrer          #+#    #+#             */
/*   Updated: 2024/02/24 10:29:50 by achabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG__H
#define DOG__H

#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal
{
    public:
        Dog(void);
        Dog(const Dog& copy);
        ~Dog(void);

        Dog& operator=(const Dog& rhs);

        void makeSound(void) const;
        Brain* getBrain(void) const;

    private:
        Brain* _brain;
};

#endif