/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 10:11:56 by achabrer          #+#    #+#             */
/*   Updated: 2024/03/12 18:32:59 by Axel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Span.hpp"

void clearScreen(void) { std::cout << "\033c"; }

void printBanner(const std::string &msg)
{
    const int bannerWidth = 15;
    int padding = std::max(0, (bannerWidth - static_cast<int>(msg.size())) / 2);
    std::cout << "---->";
    std::cout << std::string(padding, ' ') << msg << std::string(padding, ' ');
    std::cout << "<----" << std::endl;
}

void pressEnter(void)
{
    std::cout << "\npress ENTER to continue..." << std::endl;
    std::cin.ignore(1);
    clearScreen();
}

void subjectTest(void)
{
    Span sp = Span(5);

    printBanner("SUBJECT TEST");

    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);

    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;

    pressEnter();
}

void smallTest(void)
{
    Span obj(10);

    printBanner("SMALL TEST");
    pressEnter();

    printBanner("FILL");
    obj.fill();
    std::cout << obj << std::endl;
    pressEnter();

    printBanner("LONGEST SPAN");
    std ::cout << "span: " << obj.longestSpan() << std::endl;
    std::cout << "min: " << obj.min() << std::endl;
    std::cout << "max: " << obj.max() << std::endl;
    pressEnter();

    printBanner("SHORTEST SPAN");
    std::cout << obj.shortestSpan() << std::endl;
    pressEnter();
}

void bigTest(void)
{
    Span obj(10000);

    obj.fill();

    printBanner("LONGEST SPAN");
    std ::cout << "span: " << obj.longestSpan() << std::endl;
    std::cout << "min: " << obj.min() << std::endl;
    std::cout << "max: " << obj.max() << std::endl;
    pressEnter();

    printBanner("SHORTEST SPAN");
    std::cout << obj.shortestSpan() << std::endl;
    pressEnter();
}

int main(void)
{
    std::srand(time(NULL));

    clearScreen();
    subjectTest();
    smallTest();
    bigTest();

    return (EXIT_SUCCESS);
}
