/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 10:53:23 by achabrer          #+#    #+#             */
/*   Updated: 2024/03/11 23:10:01 by Axel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScalarConverter.hpp"

void clearScreen(void) { std::cout << "\033c"; }

void pressEnter(void) {
  std::cout << "\nPress ENTER to continue...";
  std::cin.get();
  std::cin.ignore(10000, '\n');
  clearScreen();
}

int main(void) {
  std::string scalar;

  while (42) {
    clearScreen();
    std::cout << "Enter a scalar to convert" << std::endl;
    std::cin >> scalar;
    ScalarConverter::convert(scalar);
    pressEnter();
  }
  return (EXIT_SUCCESS);
}
