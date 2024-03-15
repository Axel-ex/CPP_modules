/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 12:03:47 by achabrer          #+#    #+#             */
/*   Updated: 2024/02/26 14:17:50 by achabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RobotomyRequestForm.hpp"

RobotomyRequestForm ::RobotomyRequestForm(const std::string& target)
    : AForm("Robotomy", 72, 45), _target(target)
{
    LOG("Robotomy constructor called");
}

RobotomyRequestForm ::RobotomyRequestForm(const RobotomyRequestForm& src)
    : AForm(src)
{
    LOG("Robotomy copy constructor called");
    *this = src;
}

RobotomyRequestForm ::~RobotomyRequestForm(void)
{
    LOG("Robotomy destructor called");
}

RobotomyRequestForm&
RobotomyRequestForm ::operator=(const RobotomyRequestForm& rhs)
{
    if (this != &rhs)
    {
        AForm::operator=(rhs);
        _target = rhs._target;
    }
    return (*this);
}

void RobotomyRequestForm ::execute(void) const
{
    std::cout << "* PAINFULL DRILLING NOISE *" << std::endl;
    for (int i = 0; i < 6; i++)
    {
        std::cout << ".";
        std::cout.flush();
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
    if (std::rand() % 2 == 0)
        return (std::cout << "Robotomy failed..." << std::endl, void());
    std::cout << std::endl;
    std::cout << _target << " succefully lobotomised." << std::endl;
}
