/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 15:45:35 by achabrer          #+#    #+#             */
/*   Updated: 2024/03/15 13:20:43 by Axel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Point.hpp"
#include <ios>
#include <iostream>

#define GREEN "\033[38;5;47m"
#define YELLOW "\033[38;5;226m"
#define RESET "\033[0m"

#define SCENE_WIDTH 60
#define SCENE_HEIGHT 30
#define DEBUG true

bool pointEqual(Point a, Point b) { return (a == b); }

void drawScene(Point a, Point b, Point c, Point p)
{
    for (int i = 0; i < SCENE_HEIGHT; i++)
    {
        for (int j = 0; j < SCENE_WIDTH; j++)
        {
            Point curr(i, j);
            if (bsp(a, b, c, curr) && !pointEqual(p, curr))
                std::cout << GREEN << "x" << RESET;
            else if (pointEqual(p, curr))
                std::cout << YELLOW << "p" << RESET;
            else
                std::cout << ".";
        }
        std::cout << std::endl;
    }
}

static void debug(Point p, Point a, Point b, Point c, bool debug)
{
    if (!debug)
        return;
    Fixed ABC = GetTriangleArea(a, b, c);
    Fixed PAB = GetTriangleArea(p, a, b);
    Fixed PAC = GetTriangleArea(p, a, c);
    Fixed PCB = GetTriangleArea(p, b, c);

    std::cout << "ABC: " << ABC << std::endl;
    std::cout << "PAB: " << PAB << std::endl;
    std::cout << "PAC: " << PAC << std::endl;
    std::cout << "PCB: " << PCB << std::endl;
}

void clearScreen(void) { std::cout << "\033c"; }

void pressEnter(void)
{
    std::cout << "\nPress ENTER to continue...";
    std::cin.ignore(10000, '\n');
    clearScreen();
}

void printBanner(const std::string& msg)
{
    clearScreen();
    const int bannerWidth = 15;
    int padding = std::max(0, (bannerWidth - static_cast<int>(msg.size())) / 2);
    std::cout << "---->";
    std::cout << std::string(padding, ' ') << msg << std::string(padding, ' ');
    std::cout << "<----" << std::endl;
}

void intTEST(void)
{
    printBanner("INT TEST");
    pressEnter();

    Point a(Fixed(0), Fixed(0));
    Point b(Fixed(10), Fixed(30));
    Point c(Fixed(20), Fixed(0));
    Point p(Fixed(10), Fixed(15));

    drawScene(a, b, c, p);
    debug(p, a, b, c, DEBUG);
    std::cout << std::boolalpha << bsp(a, b, c, p);

    pressEnter();
}

void floatTest(void)
{
    printBanner("FLOAT TEST");
    pressEnter();

    Point a(Fixed(1.2f), Fixed(2.3f));
    Point b(Fixed(10.5f), Fixed(31.2f));
    Point c(Fixed(20.3f), Fixed(2));
    Point p(Fixed(10.6f), Fixed(15.7f));

    drawScene(a, b, c, p);
    debug(p, a, b, c, DEBUG);
    std::cout << std::boolalpha << bsp(a, b, c, p);

    pressEnter();
}

void edgeTest(void)
{
    printBanner("EDGE TEST");
    pressEnter();

    Point a(Fixed(0), Fixed(0));
    Point b(Fixed(10), Fixed(30));
    Point c(Fixed(20), Fixed(0));
    Point p(Fixed(20), Fixed(0));

    drawScene(a, b, c, p);
    debug(p, a, b, c, DEBUG);
    std::cout << std::boolalpha << bsp(a, b, c, p);

    pressEnter();
}

int main(void)
{
    intTEST();
    floatTest();
    edgeTest();

    return (EXIT_SUCCESS);
}
