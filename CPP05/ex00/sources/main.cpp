/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 15:19:26 by achabrer          #+#    #+#             */
/*   Updated: 2024/02/23 16:25:56 by achabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include <iostream>

void printUsage(void)
{
    std::cout << "usage: ./ex00 <name> <grade>";
    exit(EXIT_FAILURE);
}

void clearScreen(void) { std::cout << "\033c"; }

void pressEnter(void)
{
    std::cout << "\nPress ENTER to continue...";
    std::cin.ignore(10000, '\n');
    std::cin.ignore(10000, '\n');
    clearScreen();
}

Bureaucrat init(const std::string &name, int grade)
{
    try
    {
        return (Bureaucrat(name, grade));
    }
    catch (std::exception &e)
    {
        std::cout << RED << e.what() << RESET << std::endl;
        std::cout << "retry with a valid grade" << std::endl;
        exit(1);
    }
}

void printCommands(void)
{
    std::cout << "Enter one of the following command:" << std::endl;
    std::cout << "\tshow" << std::endl;
    std::cout << "\tincrement" << std::endl;
    std::cout << "\tdecrement" << std::endl;
    std::cout << "\texit" << std::endl;
}

int main(int argc, char **argv)
{
    std::string name;
    int grade;
    std::string command;

    if (argc < 3)
        printUsage();

    name = argv[1];
    grade = std::stoi(argv[2]);
    Bureaucrat jeff = init(name, grade);

    while (42)
    {
        printCommands();
        std::cin >> command;
        try
        {
            if (command == "show")
                std::cout << jeff << std::endl;
            if (command == "increment")
                jeff.incrementGrade();
            if (command == "decrement")
                jeff.decrementGrade();
            if (command == "exit")
                exit(EXIT_SUCCESS);
            pressEnter();
        }
        catch (std::exception &e)
        {
            std::cout << RED << e.what() << RESET << std::endl;
            pressEnter();
        }
    }
    return (EXIT_SUCCESS);
}