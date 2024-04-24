/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 13:38:27 by achabrer          #+#    #+#             */
/*   Updated: 2024/04/24 09:56:12 by achabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL__H
#define AANIMAL__H

#include <iostream>

#define DEBUG

#ifdef DEBUG
#define LOG(str) std::cout << str << std::endl
#else
#define LOG(str)
#endif

class AAnimal
{
    protected:
        std::string _type;

    public:
        AAnimal(void);
        AAnimal(const AAnimal& copy);
        virtual ~AAnimal(void);

        AAnimal& operator=(const AAnimal& rhs);
        std::string getType(void) const;
        void setType(const std::string& type);
        virtual void makeSound(void) const = 0;
};

#endif
