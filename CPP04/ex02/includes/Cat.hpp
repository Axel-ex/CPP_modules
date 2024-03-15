/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 13:40:56 by achabrer          #+#    #+#             */
/*   Updated: 2024/02/24 10:37:39 by achabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT__H
#define CAT__H

#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal
{
    public:
        Cat(void);
        Cat(const Cat& copy);
        ~Cat(void);

        Cat& operator=(const Cat& rhs);

        void makeSound(void) const;
        Brain* getBrain(void) const;

    private:
        Brain* _brain;
};

std::ostream& operator<<(std::ostream& ofs, const Cat& rhs);

#endif