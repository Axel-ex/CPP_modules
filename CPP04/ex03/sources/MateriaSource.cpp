/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 09:46:29 by achabrer          #+#    #+#             */
/*   Updated: 2024/02/24 18:21:47 by achabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/MateriaSource.hpp"

// CONSTRUCTORS
MateriaSource ::MateriaSource(void) : _source()
{
    LOG("MateriaSource constructor called");
}

MateriaSource ::MateriaSource(const MateriaSource &copy)
{
    LOG("MateriaSource copy constructor called");
    *this = copy;
}

MateriaSource ::~MateriaSource(void)
{
    LOG("MateriaSource destructor called");
    for (int i = 0; i < MAX_ITEMS; i++)
    {
        if (!_source[i])
            continue;
        delete _source[i];
    }
}

// OPERATOR OVERLOAD
std::ostream &operator<<(std::ostream &ofs, const MateriaSource &rhs)
{
    for (int i = 0; i < MAX_ITEMS; i++)
        rhs.displayMateria(i, ofs);
    return (ofs);
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
MateriaSource &MateriaSource ::operator=(const MateriaSource &rhs)
{
    if (this == &rhs)
        return (*this);
    for (int i = 0; i < MAX_ITEMS; i++)
    {
        if (_source[i])
        {
            delete _source[i];
            _source[i] = NULL;
        }
        if (rhs._source[i])
            _source[i] = rhs._source[i]->clone();
    }
    return (*this);
}

// MEMBER FUNCTIONS
void MateriaSource ::learnMateria(AMateria *m)
{
    if (m->getIsTaken())
    {
        LOG("Can't store the materia, it is already taken");
        return;
    }
    for (int i = 0; i < MAX_ITEMS; i++)
    {
        if (_source[i])
            continue;
        _source[i] = m;
        m->setIsTaken(true);
        return;
    }
    Floor::dropMateria(m);
}

AMateria *MateriaSource ::createMateria(const std::string &type)
{
    for (int i = 0; i < MAX_ITEMS; i++)
    {
        if (_source[i] && _source[i]->getType() == type)
        {
            AMateria *new_materia = _source[i]->clone();
            new_materia->setIsTaken(false);
            return (new_materia);
        }
    }
    return (NULL);
}

void MateriaSource ::displayMateria(int idx, std::ostream &ofs) const
{
    if (idx < 0 || idx >= MAX_ITEMS)
        return;
    if (_source[idx])
        ofs << _source[idx]->getType() << std::endl;
}
