/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 16:31:36 by achabrer          #+#    #+#             */
/*   Updated: 2024/02/26 17:03:14 by achabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Form.hpp"

Form ::Form(const std::string &name, int sign_grade, int exec_grade)
    : _name(name), _is_signed(false), SIGN_GRADE(sign_grade),
      EXEC_GRADE(exec_grade)
{
    if (SIGN_GRADE < MAX_GRADE || EXEC_GRADE < MAX_GRADE)
        throw Form::GradeTooHighException();
    if (SIGN_GRADE > MIN_GRADE || EXEC_GRADE > MIN_GRADE)
        throw Form::GradeTooLowException();
}

Form ::Form(const Form &src)
    : _name(src._name), SIGN_GRADE(src.SIGN_GRADE), EXEC_GRADE(src.EXEC_GRADE)
{
    *this = src;
}

Form ::~Form(void) {}

// OPERATOR OVERLOAD
Form &Form ::operator=(const Form &rhs)
{
    if (this != &rhs)
        _is_signed = rhs._is_signed;
    return (*this);
}

std::ostream &operator<<(std::ostream &ofs, const Form &rhs)
{
    std::string sign = rhs.IsSigned() ? " ✅ " : " ❌ ";

    ofs << "FORM" << std::endl;
    ofs << "name: " << rhs.getName() << std::endl;
    ofs << "min grade to sign: " << rhs.getSignGrade() << std::endl;
    ofs << "is signed: " << sign << std::endl;
    return (ofs);
}

// GETTERS // SETTERS
std::string Form ::getName(void) const { return (_name); }

bool Form ::IsSigned(void) const { return (_is_signed); }

int Form ::getSignGrade(void) const { return (SIGN_GRADE); }

int Form ::getExecGrade(void) const { return (EXEC_GRADE); }

void Form ::beSigned(const Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > SIGN_GRADE)
        throw Form ::GradeTooLowException();
    _is_signed = true;
}

// EXCEPTIONS
const char *Form ::GradeTooHighException ::what(void) const throw()
{
    return ("Grade too high");
}

const char *Form ::GradeTooLowException ::what(void) const throw()
{
    return ("Grade too low");
}