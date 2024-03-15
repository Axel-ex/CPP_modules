/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:00:51 by achabrer          #+#    #+#             */
/*   Updated: 2024/03/14 11:08:17 by Axel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Animal.hpp"
#include "../includes/Cat.hpp"
#include "../includes/Dog.hpp"
#include "../includes/WrongAnimal.hpp"
#include "../includes/WrongCat.hpp"

void clearScreen(void) { std::cout << "\033c"; }

void pressEnter(void)
{
    std::cout << "\nPress ENTER to continue...";
    std::cin.ignore(10000, '\n');
    clearScreen();
}

void printBanner(const std::string& msg)
{
    const int bannerWidth = 15;
    int padding = std::max(0, (bannerWidth - static_cast<int>(msg.size())) / 2);
    std::cout << "---->";
    std::cout << std::string(padding, ' ') << msg << std::string(padding, ' ');
    std::cout << "<----" << std::endl;
}

void basicTest(void)
{
    printBanner("BASIC TESTS");
    pressEnter();

    printBanner("CREATION");
    Animal* ptr[3] = {new Cat(), new Cat(), new Dog()};
    pressEnter();

    printBanner("METHOD make");
    for (int i = 0; i < 3; i++)
        ptr[i]->makeSound();
    pressEnter();

    printBanner("DELETION");
    for (int i = 0; i < 3; i++)
        delete ptr[i];
    pressEnter();
}

void WrongAnimalTest(void)
{
    printBanner("WRONG CAT TEST");
    pressEnter();

    printBanner("CREATION");
    WrongAnimal* wrong = new WrongCat();
    pressEnter();

    printBanner("METHOD");
    wrong->makeSound();
    pressEnter();

    printBanner("DELETION");
    delete wrong;
    pressEnter();
}

int main(void)
{
    clearScreen();
    basicTest();
    WrongAnimalTest();

    return (EXIT_SUCCESS);
}
