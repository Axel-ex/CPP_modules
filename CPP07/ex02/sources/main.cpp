/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 15:11:58 by achabrer          #+#    #+#             */
/*   Updated: 2024/03/12 18:29:19 by Axel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Array.hpp"

void clearScreen(void) { std::cout << "\033c"; }

void pressEnter(void)
{
    std::cout << "\nPress ENTER to continue...";
    std::cin.ignore(10000, '\n');
    clearScreen();
}

void printBanner(const std::string &msg)
{
    const int bannerWidth = 15;
    int padding = std::max(0, (bannerWidth - static_cast<int>(msg.size())) / 2);
    std::cout << "---->";
    std::cout << std::string(padding, ' ') << msg << std::string(padding, ' ');
    std::cout << "<----" << std::endl;
}

void outOfRangeTest(void)
{
    Array<int> arr1 = Array<int>(5);

    printBanner("OUT OF RANGE TEST");
    try
    {
        arr1[10];
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    pressEnter();
}

template <typename T> void basicTest(std::string test_name)
{
    printBanner(test_name);
    pressEnter();

    Array<T> arr = Array<T>(5);

    printBanner("INIT VALUES");
    for (int i = 0; i < arr.size(); i++)
        std::cout << arr[i] << std::endl;
    pressEnter();
}

void copyTest(void)
{
    printBanner("COPY TEST");
    pressEnter();

    Array<std::string> arr = Array<std::string>(5);
    Array<std::string> arr2 = Array<std::string>(5);

    for (int i = 0; i < arr.size(); i++)
    {
        arr[i] = "42";
        arr2[i] = "lol";
    }

    printBanner("BEFORE COPY");
    std::cout << "Array 1: ";
    for (int i = 0; i < arr.size(); i++)
        std::cout << arr[i] << ", ";
    std::cout << std::endl << "Array 2: ";
    for (int i = 0; i < arr2.size(); i++)
        std::cout << arr2[i] << ", ";
    pressEnter();

    arr = arr2;

    printBanner("AFTER COPY");
    std::cout << "Array 1: ";
    for (int i = 0; i < arr.size(); i++)
        std::cout << arr[i] << ", ";
    std::cout << std::endl << "Array 2: ";
    for (int i = 0; i < arr2.size(); i++)
        std::cout << arr2[i] << ", ";
    pressEnter();
}

int main(void)
{
    clearScreen();
    basicTest<int>("INT TEST");
    basicTest<char>("CHAR TEST");
    basicTest<std::string>("STRING TEST");
    copyTest();
    outOfRangeTest();

    return (EXIT_SUCCESS);
}
