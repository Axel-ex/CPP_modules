/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 11:59:35 by achabrer          #+#    #+#             */
/*   Updated: 2024/02/26 13:49:25 by achabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMY_HPP
#define ROBOTOMY_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <thread>
#include <chrono>
#include <random>

class	RobotomyRequestForm : public AForm
{
	public:
		RobotomyRequestForm( const std::string &target );
		RobotomyRequestForm( const RobotomyRequestForm &src );
		~RobotomyRequestForm( void );

		RobotomyRequestForm &operator=( const RobotomyRequestForm &rhs );

		virtual void	execute( void )	const;
		
	private:
		std::string _target;
};

#endif