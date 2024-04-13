/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 21:00:40 by achabrer          #+#    #+#             */
/*   Updated: 2024/04/13 18:47:36 by achabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>

int main(void)
{
    std::string const str = "HI THIS IS BRAIN";
    std::string const* strPTR = &str;
    std::string const& strREF = str;

    std::cout << "MEMORY ADDRESSES:" << std::endl;
    std::cout << "\tstr:\t" << &str << std::endl;
    std::cout << "\tstrPTR:\t" << strPTR << std::endl;
    std::cout << "\tstrREF:\t" << &strREF << std::endl << std::endl;

    std::cout << "VALUES:\t" << std::endl;
    std::cout << "\tstr:\t" << str << std::endl;
    std::cout << "\tstrPTR:\t" << *strPTR << std::endl;
    std::cout << "\tstrREF:\t" << strREF << std::endl;

    return (EXIT_SUCCESS);
}
