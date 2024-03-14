/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Floor.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 13:44:06 by achabrer          #+#    #+#             */
/*   Updated: 2024/02/22 16:40:01 by achabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Floor.hpp"

Floor ::Floor(void) : _materia_list()
{
    LOG("Floor default constructor called");
}

Floor ::~Floor(void)
{
    LOG("Floor destructor called");
    deleteMaterias();
}

void Floor ::pushFront(AMateria *materia)
{
    if (materia->getIsTaken())
    {
        LOG("Can't put a taken materia on the floor");
        return;
    }
    LOG("Materia droped on the floor");

    MateriaList *new_node = new MateriaList;
    new_node->materia = materia;
    new_node->next = _materia_list;
    _materia_list = new_node;
}

void Floor ::deleteMaterias(void)
{
    LOG("Cleaning the floor");
    MateriaList *tmp;

    while (_materia_list)
    {
        tmp = _materia_list;
        _materia_list = _materia_list->next;
        delete tmp->materia;
        delete tmp;
    }
}

void Floor ::Idisplaylist(void)
{
    MateriaList *current = _materia_list;

    while (current)
    {
        std::cout << "\t" << current->materia->getType() << std::endl;
        current = current->next;
    }
}

// STATIC MEMBERS
/**
 * @brief return the instance of Floor. SINGLETON pattern
 *
 * @return Floor&
 */
Floor &Floor ::getInstance(void)
{
    static Floor instance;

    return (instance);
}

// The following functions are made to avoid heavy synthax
// Floor::getInstance().pushFront() could adopt a convention like:
// Idisplaylist(internal), displayList(accessible)
void Floor ::dropMateria(AMateria *materia)
{
    getInstance().pushFront(materia);
}

void Floor ::displayList(void)
{
    std::cout << "Currently on the floor: " << std::endl;
    getInstance().Idisplaylist();
}
