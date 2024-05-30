/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 10:11:56 by achabrer          #+#    #+#             */
/*   Updated: 2024/05/30 13:28:20 by achabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/easyfind.hpp"
#include <cstdlib>
#include <ctime>
#include <deque>
#include <vector>

#define RED "\033[31m"
#define RESET "\033[0m"

void clearScreen(void) { std::cout << "\033c"; }

void pressEnter(void)
{
    std::cout << "press ENTER to continue..." << std::endl;
    std::cin.ignore(1);
    clearScreen();
}

template <typename T> void fillContainer(T& cont)
{
    for (int i = 0; i < 100; i++)
        cont.push_back(rand() % 100);
}

template <typename T> void displayContainer(T& cont, int to_find)
{
    for (size_t i = 0; i < cont.size(); i++)
    {
        std::cout << i << ") ";
        if (cont[i] == to_find)
            std::cout << RED << cont[i] << RESET << std::endl;
        else
            std::cout << cont[i] << std::endl;
    }
}

template <typename T> void basicTest(T& cont, std::string test_name)
{
    std::cout << "\t" << test_name << std::endl << std::endl;
    fillContainer(cont);
    displayContainer(cont, 42);
    pressEnter();

    try
    {
        int pos = easyfind<T>(cont, 42);
        std::cout << "Found 42 at the index [" << pos << "]" << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    pressEnter();
}

int main(void)
{
    srand(time(NULL));
    std::vector<int> vect;
    std::deque<int> queue;

    clearScreen();
    basicTest<std::vector<int> >(vect, "VECTOR");
    basicTest<std::deque<int> >(queue, "QUEUE");

    return (EXIT_SUCCESS);
}
