/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 14:26:03 by achabrer          #+#    #+#             */
/*   Updated: 2024/02/26 15:36:05 by achabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
    public:
        Intern(void);
        Intern(const Intern& src);
        ~Intern(void);

        Intern& operator=(const Intern& rhs);

        AForm* makeForm(const std::string& name,
                        const std::string& target) const;
        AForm* makeShrubberyForm(const std::string& target) const;
        AForm* makeRobotomyForm(const std::string& target) const;
        AForm* makePresidentialForm(const std::string& target) const;

        class FormRequestException : public std::exception
        {
            public:
                virtual const char* what(void) const throw();
        };
};

#endif
