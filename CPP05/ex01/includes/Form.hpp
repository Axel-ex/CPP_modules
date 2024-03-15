/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 16:12:46 by achabrer          #+#    #+#             */
/*   Updated: 2024/02/23 22:14:45 by achabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"
#include <iostream>

class Bureaucrat;

class Form
{
    public:
        Form(const std::string& name, int sign_grade, int exec_grade);
        Form(const Form& src);
        ~Form(void);

        Form& operator=(const Form& rhs);

        std::string getName(void) const;
        int getSignGrade(void) const;
        int getExecGrade(void) const;
        bool IsSigned(void) const;

        void beSigned(const Bureaucrat& bureaucrat);

        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };

    private:
        const std::string _name;
        bool _is_signed;
        const int SIGN_GRADE;
        const int EXEC_GRADE;
        static const int MAX_GRADE = 1;
        static const int MIN_GRADE = 150;
};

std::ostream& operator<<(std::ostream& ofs, const Form& rhs);

#endif