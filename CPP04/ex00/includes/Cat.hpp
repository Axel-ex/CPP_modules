/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 13:40:56 by achabrer          #+#    #+#             */
/*   Updated: 2024/02/20 14:07:00 by achabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT__H
#define CAT__H

#include "Animal.hpp"

class Cat : public Animal
{
    public:
        Cat(void);
        Cat(const Cat &copy);
        ~Cat(void);

        Cat &operator=(const Cat &rhs);

        void makeSound(void) const;
};

#endif