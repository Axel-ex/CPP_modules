/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 15:43:52 by achabrer          #+#    #+#             */
/*   Updated: 2024/02/23 22:17:36 by achabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include "ICharacter.hpp"
#include <iostream>

#ifdef DEBUG
#define LOG(str) std::cout << str << std::endl
#else
#define LOG(str)
#endif

class ICharacter;

class AMateria
{
    public:
        AMateria(void);
        AMateria(const std::string& type);
        virtual ~AMateria(void);

        bool getIsTaken(void) const;
        void setIsTaken(bool set_value);
        const std::string& getType(void) const;

        virtual void use(ICharacter& target);
        virtual AMateria* clone(void) const = 0;

    protected:
        std::string _type;
        bool _is_taken;
};

#endif