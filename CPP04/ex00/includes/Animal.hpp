/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 13:38:27 by achabrer          #+#    #+#             */
/*   Updated: 2024/02/24 09:58:24 by achabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL__H
#define ANIMAL__H

#include <iostream>

class Animal
{
    public:
        Animal(void);
        Animal(const Animal& copy);
        virtual ~Animal(void);

        Animal& operator=(const Animal& rhs);
        std::string getType(void) const;
        void setType(const std::string& type);
        virtual void makeSound(void) const;

    protected:
        std::string _type;
};

#endif