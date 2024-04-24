/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:00:51 by achabrer          #+#    #+#             */
/*   Updated: 2024/04/24 09:58:30 by achabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AAnimal.hpp"
#include "../includes/Cat.hpp"
#include "../includes/Dog.hpp"
#include <cstdlib>

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
    AAnimal* ptr[3] = {new Cat(), new Cat(), new Dog()};
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

void brainTest(void)
{
    printBanner("BRAIN TEST");
    pressEnter();

    printBanner("SETTING IDEAS");
    Cat cat = Cat();
    for (int i = 0; i < 5; i++)
        cat.getBrain()->setIdea("*thinking about food*", i);
    pressEnter();

    printBanner("DISPLAY OBJECT");
    std::cout << cat << std::endl;
    pressEnter();

    printBanner("BRAIN LIMITS");
    try
    {
        std::cout << "setting idea at index 101" << std::endl;
        cat.getBrain()->setIdea("Out limits", 101);
    }
    catch (std::exception& e)
    {
        std::cout << "EXCEPTION CAUGHT" << std::endl;
        std::cout << e.what() << std::endl;
    }
    pressEnter();

    printBanner("DESTRUCTION");
}

void AbstractClassTest(void)
{
    // Do not compile
    /* AAnimal	animal = AAnimal(); */
}

int main(void)
{
    clearScreen();
    basicTest();
    brainTest();
    AbstractClassTest();

    return (EXIT_SUCCESS);
}
