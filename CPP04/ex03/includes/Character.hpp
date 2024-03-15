/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 08:29:53 by achabrer          #+#    #+#             */
/*   Updated: 2024/02/24 18:08:09 by achabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "Floor.hpp"
#include "ICharacter.hpp"

#define MAX_ITEMS 4

class Character : public ICharacter
{
    public:
        Character(void);
        Character(const std::string& name);
        Character(const Character& copy);
        ~Character(void);

        Character& operator=(const Character& rhs);

        const std::string& getName(void) const;
        AMateria* getItem(int idx) const;

        void equip(AMateria* m);
        void unequip(int idx);
        void use(int idx, ICharacter& target);

    private:
        AMateria* _inventory[MAX_ITEMS];
        std::string _name;
};

std::ostream& operator<<(std::ostream& ofs, const Character& rhs);

#endif