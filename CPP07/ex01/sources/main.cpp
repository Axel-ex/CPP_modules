/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 11:35:31 by achabrer          #+#    #+#             */
/*   Updated: 2024/05/30 10:57:29 by achabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/iter.hpp"
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

template <typename T> void add5(T& elem) { elem += 5; }

template <typename T> void test(T* arr, size_t size, std::string test_type)
{
    printBanner(test_type);
    pressEnter();

    T* tmp = arr;

    printBanner("BEFORE");
    for (size_t i = 0; i < size; i++)
        std::cout << tmp[i] << std::endl;
    pressEnter();

    iter<T>(arr, size, add5<T>);

    printBanner("AFTER");
    for (size_t i = 0; i < size; i++)
        std::cout << tmp[i] << std::endl;
    pressEnter();
}

int main(void)
{
    int arr1[3] = {1, 2, 3};
    char arr2[3] = {'h', 'e', 'y'};

    test<int>(arr1, 3, "ARRAY OF INTS");
    test<char>(arr2, 3, "ARRAY OF CHAR");
}
