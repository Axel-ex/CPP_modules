/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 14:32:53 by achabrer          #+#    #+#             */
/*   Updated: 2024/02/26 15:43:58 by achabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Intern.hpp"

Intern ::Intern(void) { LOG("Intern constructor called"); }

Intern ::Intern(const Intern& src)
{
    LOG("Intern copy constructor called");
    *this = src;
}

Intern ::~Intern(void) { LOG("Intern destructor called"); }

Intern& Intern ::operator=(const Intern& rhs)
{
    (void)rhs;
    return (*this);
}

AForm* Intern ::makeForm(const std::string& name,
                         const std::string& target) const
{
    AForm* (Intern::*factory[3])(const std::string&) const = {
        &Intern::makeShrubberyForm,
        &Intern::makeRobotomyForm,
        &Intern::makePresidentialForm,
    };
    std::string names[3] = {"shrubbery", "robotomy", "presidential"};
    for (int i = 0; i < 3; i++)
        if (name == names[i])
            return ((this->*factory[i])(target));
    throw Intern::FormRequestException();
}

AForm* Intern ::makeShrubberyForm(const std::string& target) const
{
    return (new ShrubberyCreationForm(target));
}

AForm* Intern ::makeRobotomyForm(const std::string& target) const
{
    return (new RobotomyRequestForm(target));
}

AForm* Intern ::makePresidentialForm(const std::string& target) const
{
    return (new PresidentialPardonForm(target));
}

const char* Intern ::FormRequestException ::what(void) const throw()
{
    return ("Invalid form type requested");
}