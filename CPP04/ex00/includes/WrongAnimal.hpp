/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:56:58 by achabrer          #+#    #+#             */
/*   Updated: 2024/02/24 09:58:44 by achabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL__H
#define WRONGANIMAL__H

#include <iostream>

class WrongAnimal
{
    public:
        WrongAnimal(void);
        WrongAnimal(const WrongAnimal& copy);
        virtual ~WrongAnimal(void);

        WrongAnimal& operator=(const WrongAnimal& rhs);
        std::string getType(void) const;
        void setType(const std::string& type);
        void makeSound(void) const;

    protected:
        std::string _type;
};

#endif