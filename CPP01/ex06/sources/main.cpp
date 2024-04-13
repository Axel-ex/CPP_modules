/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 11:47:59 by achabrer          #+#    #+#             */
/*   Updated: 2024/04/13 19:08:37 by achabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Harl.hpp"
#include <cstdlib>

int print_error(std::string msg)
{
    std::cout << msg << std::endl;
    exit(EXIT_FAILURE);
}

int main(int argc, char** argv)
{
    if (argc < 2)
        print_error("Enter a log level");

    Harl harl;
    std::string level = argv[1];
    std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

    int index = -1;
    for (int i = 0; i < 4; i++)
        if (levels[i] == level)
            index = i;

    switch (index)
    {
    default:
        std::cout << "probably still complaining" << std::endl;
        break;
    case 0:
        std::cout << "[ DEBUG ]" << std::endl;
        harl.complain("DEBUG");
    case 1:
        std::cout << "[ INFO ]" << std::endl;
        harl.complain("INFO");
    case 2:
        std::cout << "[ WARNING ]" << std::endl;
        harl.complain("WARNING");
    case 3:
        std::cout << "[ ERROR ]" << std::endl;
        harl.complain("ERROR");
    }

    return (EXIT_SUCCESS);
}
