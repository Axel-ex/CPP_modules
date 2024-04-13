/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 11:47:59 by achabrer          #+#    #+#             */
/*   Updated: 2024/04/13 19:07:20 by achabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Harl.hpp"
#include <cstdlib>

int main(void)
{
    Harl harl;

    harl.complain("DEBUG");
    harl.complain("INFO");
    harl.complain("WARNING");
    harl.complain("ERROR");
    harl.complain("blabla");
    return (EXIT_SUCCESS);
}
