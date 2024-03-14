/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 08:44:17 by achabrer          #+#    #+#             */
/*   Updated: 2024/02/24 18:12:42 by achabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Character.hpp"

Character ::Character(void) : _inventory(), _name("Jack")
{
    LOG("Character default constructor called");
}

Character ::Character(const std::string &name) : _inventory(), _name(name)
{
    LOG("Character param constructor called");
}

Character ::Character(const Character &copy)
{
    LOG("Character copy constructor called");
    *this = copy;
}

Character ::~Character(void)
{
    LOG("Character destructor called");
    for (int i = 0; i < MAX_ITEMS; i++)
    {
        if (_inventory[i])
            delete _inventory[i];
    }
}

/**
 * @brief Deep copies the rhs object.
 * Since our class implements a container of objects with polymorphic behavior,
 * the clone() function allows us to avoid slicing. Slicing occurs when only
 * the constructor of the base class is called on an object of derived class
 * type, resulting in the derived part of the object being "sliced away".
 *
 * @param rhs
 * @return MateriaSource&
 */
Character &Character ::operator=(const Character &rhs)
{
    if (this == &rhs)
        return (*this);
    for (int i = 0; i < MAX_ITEMS; i++)
    {
        if (_inventory[i])
        {
            delete _inventory[i];
            _inventory[i] = NULL;
        }
        if (rhs._inventory[i])
            _inventory[i] = rhs._inventory[i]->clone();
    }
    return (*this);
}

std::ostream &operator<<(std::ostream &ofs, const Character &rhs)
{
    std::cout << "name: " << rhs.getName() << std::endl;
    std::cout << "inventory: " << std::endl;
    for (int i = 0; i < MAX_ITEMS; i++)
    {
        if (rhs.getItem(i))
            std::cout << "\t" << rhs.getItem(i)->getType() << std::endl;
    }
    return (ofs);
}

// MEMBER FUNCTIONS
const std::string &Character ::getName(void) const { return (_name); }

AMateria *Character ::getItem(int idx) const
{
    if (idx < 0 || idx > MAX_ITEMS)
        return (NULL);
    return (_inventory[idx]);
}

void Character ::equip(AMateria *m)
{
    if (!m || m->getIsTaken())
    {
        LOG("Materia is already taken");
        return;
    }
    for (int i = 0; i < MAX_ITEMS; i++)
    {
        if (!_inventory[i])
        {
            _inventory[i] = m;
            m->setIsTaken(true);
            return;
        }
    }
    Floor::dropMateria(m);
}

void Character ::unequip(int idx)
{
    if (idx >= MAX_ITEMS || idx < 0)
        return;
    Floor::dropMateria(_inventory[idx]);
    _inventory[idx] = NULL;
}

void Character ::use(int idx, ICharacter &target)
{
    if (idx >= MAX_ITEMS || idx < 0)
        return;
    if (_inventory[idx])
        _inventory[idx]->use(target);
}