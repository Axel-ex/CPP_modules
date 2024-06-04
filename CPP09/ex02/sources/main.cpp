/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 11:02:15 by achabrer          #+#    #+#             */
/*   Updated: 2024/06/04 12:06:34 by achabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PmergeMe.hpp"
#include <stdexcept>

int main(int argc, char** argv)
{
    try
    {
        if (argc < 2)
            throw std::runtime_error("Enter a valid nb of args");
        PmergeMe merger;
        merger.readArgs(argv, argc);
        merger.compute();
    }
	catch(std::runtime_error &e)
	{
		std::cout << "Invalid token: " << e.what() << std::endl;
	}
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
}
