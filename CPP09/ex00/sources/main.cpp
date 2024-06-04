/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 14:36:52 by achabrer          #+#    #+#             */
/*   Updated: 2024/06/04 10:24:39 by achabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/BitcoinExchange.hpp"
#include "cstdlib"

int main(int argc, char** argv)
{
    try
    {
        if (argc < 2)
            throw std::runtime_error(FILE_NT_FND);
        BitcoinExchange btc(argv[1]);
        btc.compute();
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    return (EXIT_SUCCESS);
}
