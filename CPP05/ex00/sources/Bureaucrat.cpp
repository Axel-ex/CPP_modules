/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 14:35:00 by achabrer          #+#    #+#             */
/*   Updated: 2024/02/23 17:07:20 by achabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"

Bureaucrat ::Bureaucrat(const std::string& name, int grade)
    : _name(name), _grade(grade)
{
    LOG("Bureaucrat parametrised constructor called");
    if (grade < MAX_GRADE)
        throw Bureaucrat::GradeTooHighException();
    if (grade > MIN_GRADE)
        throw Bureaucrat::GradeTooLowException();
}

Bureaucrat ::Bureaucrat(const Bureaucrat& src)
{
    LOG("Bureaucrat copy constructor called");
    *this = src;
}

Bureaucrat ::~Bureaucrat(void) { LOG("Bureaucrat destructor called"); }

// OPERATOR OVERLOAD
Bureaucrat& Bureaucrat ::operator=(const Bureaucrat& rhs)
{
    if (this != &rhs)
        _grade = rhs._grade;
    return (*this);
}

std::ostream& operator<<(std::ostream& ofs, const Bureaucrat& rhs)
{
    ofs << rhs.getName() << std::endl;
    ofs << rhs.getGrade() << std::endl;
    return (ofs);
}

// GETTERS/SETTERS
std::string Bureaucrat ::getName(void) const { return (_name); }

int Bureaucrat ::getGrade(void) const { return (_grade); }

void Bureaucrat ::incrementGrade(void)
{
    LOG("incrementing the grade");
    if (_grade == MAX_GRADE)
        throw Bureaucrat ::GradeTooHighException();
    _grade--;
}

void Bureaucrat ::decrementGrade(void)
{
    LOG("decrementing the grade");
    if (_grade == MIN_GRADE)
        throw Bureaucrat ::GradeTooLowException();
    _grade++;
}

// EXCEPTION
const char* Bureaucrat ::GradeTooHighException ::what(void) const throw()
{
    return ("Grade is too high");
}

const char* Bureaucrat ::GradeTooLowException ::what(void) const throw()
{
    return ("Grade is too low");
}
