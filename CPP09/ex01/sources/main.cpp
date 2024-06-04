/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 14:39:29 by achabrer          #+#    #+#             */
/*   Updated: 2024/06/04 10:42:59 by achabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RPN.hpp"
#include <cstdlib>

void printUsage(void)
{
    std::cout << "\nEnter a valid reverse polish expression" << std::endl;
    std::cout << "ex: 7 7 * 7 -" << std::endl;
}

int main(int argc, char** argv)
{
    try
    {
        if (argc < 2)
            throw std::runtime_error("Enter an expression");
        RPN rpn(argv[1]);
        rpn.compute();
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
        printUsage();
    }
    return (EXIT_SUCCESS);
}
