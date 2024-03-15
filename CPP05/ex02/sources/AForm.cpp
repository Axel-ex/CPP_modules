/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 16:31:36 by achabrer          #+#    #+#             */
/*   Updated: 2024/02/26 17:02:11 by achabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AForm.hpp"

AForm ::AForm(const std::string& name, int sign_grade, int exec_grade)
    : _name(name), _is_signed(false), SIGN_GRADE(sign_grade),
      EXEC_GRADE(exec_grade)
{
    if (SIGN_GRADE < MAX_GRADE || EXEC_GRADE < MAX_GRADE)
        throw AForm::GradeTooHighException();
    if (SIGN_GRADE > MIN_GRADE || EXEC_GRADE > MIN_GRADE)
        throw AForm::GradeTooLowException();
}

AForm ::AForm(const AForm& src)
    : _name(src._name), SIGN_GRADE(src.SIGN_GRADE), EXEC_GRADE(src.EXEC_GRADE)
{
    *this = src;
}

AForm ::~AForm(void) {}

// OPERATOR OVERLOAD
AForm& AForm ::operator=(const AForm& rhs)
{
    if (this != &rhs)
        _is_signed = rhs._is_signed;
    return (*this);
}

std::ostream& operator<<(std::ostream& ofs, const AForm& rhs)
{
    std::string sign = rhs.IsSigned() ? " ✅ " : " ❌ ";

    ofs << "FORM" << std::endl;
    ofs << "name: " << rhs.getName() << std::endl;
    ofs << "is signed: " << sign << std::endl;
    ofs << "min grade to sign: " << rhs.getSignGrade() << std::endl;
    ofs << "min grade to execute: " << rhs.getExecGrade() << std::endl;
    return (ofs);
}

// GETTERS // SETTERS
std::string AForm ::getName(void) const { return (_name); }

bool AForm ::IsSigned(void) const { return (_is_signed); }

int AForm ::getSignGrade(void) const { return (SIGN_GRADE); }

int AForm ::getExecGrade(void) const { return (EXEC_GRADE); }

void AForm ::beSigned(const Bureaucrat& bureaucrat)
{
    if (bureaucrat.getGrade() > SIGN_GRADE)
        throw AForm ::GradeTooLowException();
    _is_signed = true;
}

void AForm ::setIsSigned(bool to_set) { _is_signed = to_set; }

void AForm ::execute(const Bureaucrat& executor) const
{
    if (executor.getGrade() > EXEC_GRADE)
        throw AForm::GradeTooLowException();
    if (!_is_signed)
        throw AForm::UnsignedException();
    std::cout << executor.getName() << " executed the form " << this->getName()
              << std::endl;
    this->execute();
}

// EXCEPTIONS
const char* AForm ::GradeTooHighException ::what(void) const throw()
{
    return ("Grade too high");
}

const char* AForm ::GradeTooLowException ::what(void) const throw()
{
    return ("Grade too low");
}

const char* AForm ::UnsignedException ::what(void) const throw()
{
    return ("The form was not signed");
}