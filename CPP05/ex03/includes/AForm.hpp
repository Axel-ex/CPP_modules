/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 16:12:46 by achabrer          #+#    #+#             */
/*   Updated: 2024/02/26 14:09:56 by achabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class	AForm
{
	public:
		AForm( const std::string &name, int sign_grade, int exec_grade );
		AForm( const AForm &src );
		virtual ~AForm( void );

		AForm &operator=( const AForm &rhs );

		std::string	getName( void )			const;
		int			getSignGrade( void )	const;
		int			getExecGrade( void )	const;
		bool		IsSigned( void )		const;
		void		setIsSigned( bool to_set );

		void			beSigned(const Bureaucrat &bureaucrat);	
		void			execute( const Bureaucrat &execute) const;
		virtual void	execute( void ) const = 0;


		class	GradeTooHighException : public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};
		class	GradeTooLowException : public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};
		class	UnsignedException : public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};

	private:
		const std::string	_name;
		bool				_is_signed;
		const int			SIGN_GRADE;
		const int			EXEC_GRADE;
		static const int	MAX_GRADE = 1;
		static const int	MIN_GRADE = 150;

};

std::ostream &operator<<( std::ostream &ofs, const AForm &rhs );

#endif