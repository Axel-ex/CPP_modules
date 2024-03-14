/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:28:59 by achabrer          #+#    #+#             */
/*   Updated: 2024/02/24 10:48:33 by achabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Brain.hpp"
#include "../includes/Animal.hpp"

Brain ::Brain(void) : _nb_ideas(0) { LOG("Brain default constructor called"); }

Brain ::Brain(const Brain &copy)
{
    *this = copy;
    LOG("Brain copy constructor called");
}

Brain ::~Brain(void) { LOG("Brain destructor called"); }

// OPERATOR OVERLOAD
Brain &Brain ::operator=(const Brain &rhs)
{
    if (this != &rhs)
    {
        for (int i = 0; i < MAX_IDEAS; i++)
            _ideas[i] = rhs._ideas[i];
        _nb_ideas = rhs._nb_ideas;
    }
    return (*this);
}

// MEMBER FUNCTIONS
std::string Brain ::getIdea(int index) const
{
    if (index < 0 || index > MAX_IDEAS)
        throw std::runtime_error("Ideas index out of range");
    return (_ideas[index]);
}

void Brain ::setIdea(const std::string &idea, int index)
{
    if (index < 0 || index > MAX_IDEAS)
        throw std::runtime_error("Ideas index out of range");
    _ideas[index] = idea;
    _nb_ideas++;
}

int Brain ::getNbIdea(void) const { return (_nb_ideas); }

void Brain ::print(void) const
{
    for (int i = 0; i < _nb_ideas; i++)
        std::cout << "\t" << _ideas[i] << std::endl;
}