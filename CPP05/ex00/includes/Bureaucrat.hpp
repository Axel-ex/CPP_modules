/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 14:23:58 by achabrer          #+#    #+#             */
/*   Updated: 2024/02/23 22:15:34 by achabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#ifdef DEBUG
#define LOG(str) std::cout << str << std::endl
#else
#define LOG(str)
#endif

#define RED "\033[31m"
#define RESET "\033[0m"

#include <iostream>

class Bureaucrat
{
    public:
        Bureaucrat(const std::string &name, int grade);
        Bureaucrat(const Bureaucrat &src);
        ~Bureaucrat(void);

        Bureaucrat &operator=(const Bureaucrat &rhs);

        std::string getName(void) const;
        int getGrade(void) const;
        void incrementGrade(void);
        void decrementGrade(void);

        // Exceptions. nested class to be able to use
        // Bureaucrat::GradeTooHighException
        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };
        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };

    private:
        const std::string _name;
        int _grade;
        static const int MAX_GRADE = 1;
        static const int MIN_GRADE = 150;
};

std::ostream &operator<<(std::ostream &ofs, const Bureaucrat &rhs);

#endif