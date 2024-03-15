/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 17:24:21 by achabrer          #+#    #+#             */
/*   Updated: 2024/03/14 11:03:38 by Axel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"

void printBanner(const std::string& msg)
{
    const int bannerWidth = 15;
    int padding = std::max(0, (bannerWidth - static_cast<int>(msg.size())) / 2);
    std::cout << "---->";
    std::cout << std::string(padding, ' ') << msg << std::string(padding, ' ');
    std::cout << "<----" << std::endl;
}

void limitTest(void)
{
    Bureaucrat Axel = Bureaucrat("Axel", 56);
    Form promotion = Form("promotion", 1, 2);

    printBanner("INVALID GRADE TEST");
    std::cout << Axel << std::endl;
    std::cout << promotion << std::endl;
    Axel.signForm(promotion);
    std::cout << promotion << std::endl;
}

int main(void)
{
    limitTest();
    return (EXIT_SUCCESS);
}
