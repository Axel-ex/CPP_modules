/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 13:39:34 by achabrer          #+#    #+#             */
/*   Updated: 2024/02/26 14:18:08 by achabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PresidentialPardonForm.hpp"

PresidentialPardonForm :: PresidentialPardonForm( const std::string &target )
: AForm("presidential pardon form", 25, 5), _target(target)
{
	LOG("Presidential constructor called");
}

PresidentialPardonForm :: PresidentialPardonForm( const PresidentialPardonForm &src )
: AForm(src)
{
	LOG("presidential copy constructor called");
	*this = src;
}

PresidentialPardonForm :: ~PresidentialPardonForm( void )
{
	LOG("presidential destructor called");
}

PresidentialPardonForm &PresidentialPardonForm :: operator=( const PresidentialPardonForm &rhs )
{
	if (this != &rhs)
	{
		AForm::operator=(rhs);
		_target = rhs._target;
	}
	return (*this);
}

void	PresidentialPardonForm :: execute( void ) const
{
	std::cout << _target << " has been pardonned by Zaphod Beeblebrox" << std::endl;
}