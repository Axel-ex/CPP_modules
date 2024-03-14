/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 13:06:08 by achabrer          #+#    #+#             */
/*   Updated: 2024/01/26 10:38:28 by achabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.hpp"

int main(void)
{
    PhoneBook phonebook;
    std::string cmd;

    PhoneBook::printMenu();
    while (42)
    {
        std::cout << "input> ";
        if (!std::getline(std::cin, cmd, '\n'))
            return (PhoneBook::printError("EOF"), EXIT_FAILURE);
        if (cmd == "ADD")
            phonebook.add();
        else if (cmd == "SEARCH")
            phonebook.search();
        else if (cmd == "EXIT")
            break;
        else
        {
            PhoneBook::printError("invalid command");
            continue;
        }
        PhoneBook::printMenu();
    }
    return (EXIT_SUCCESS);
}