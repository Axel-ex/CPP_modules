/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 13:36:17 by achabrer          #+#    #+#             */
/*   Updated: 2024/02/21 10:06:27 by achabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG__H
#define DOG__H

#include "Animal.hpp"

class Dog : public Animal
{
    public:
        Dog(void);
        Dog(const Dog& copy);
        ~Dog(void);

        Dog& operator=(const Dog& rhs);

        void makeSound(void) const;
};

#endif