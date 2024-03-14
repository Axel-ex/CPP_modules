/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 11:24:53 by achabrer          #+#    #+#             */
/*   Updated: 2024/02/15 12:16:58 by achabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Harl.hpp"

Harl::Harl(void) {}

Harl::~Harl(void) {}

void Harl::complain(std::string level)
{
    // Create an array of member function pointers
    void (Harl::*ptrs[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning,
                                   &Harl::error};

    // Create an array of possible levels
    std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

    for (int i = 0; i < 4; i++)
        if (levels[i] == level)
            (this->*ptrs[i])();
}

void Harl::debug(void)
{
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-"
              << "pickle-special-ketchup burger" << std::endl;
}

void Harl::info(void)
{
    std::cout << "I cannot believe adding extra bacon costs more money."
              << " You didn’t put enough bacon in my burger." << std::endl;
}

void Harl::warning(void)
{
    std::cout << "I think I deserve to have some extra bacon for free."
              << " I’ve been coming for years!" << std::endl;
}

void Harl::error(void)
{
    std::cout << "This is unacceptable! I want to speak to the manager now."
              << std::endl;
}