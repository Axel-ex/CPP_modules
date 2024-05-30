/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 10:47:44 by achabrer          #+#    #+#             */
/*   Updated: 2024/05/30 15:40:25 by achabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/MutantStack.hpp"
#include <cstdlib>

void clearScreen(void) { std::cout << "\033c"; }

void printBanner(const std::string& msg)
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
    printBanner("SUBJECT TEST");
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    //[...]
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }

    std::stack<int> s(mstack);
    pressEnter();
}

void myTest(void)
{
    MutantStack<std::string> s;

    printBanner("MY TEST");
    s.push("hello");
    s.push("my");
    s.push("friends");

    std::deque<std::string>::iterator it;
    for (it = s.begin(); it != s.end(); it++)
    {
        *it = "lol";
        std::cout << *it << std::endl;
    }
}

int main(void)
{
    clearScreen();
    subjectTest();
    myTest();

    return (EXIT_SUCCESS);
}
