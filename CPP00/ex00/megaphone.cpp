/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 11:40:48 by achabrer          #+#    #+#             */
/*   Updated: 2024/01/25 10:18:47 by achabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

void	print_upper(const char *s)
{
	for (int i = 0; s[i]; i++)
		std::cout << static_cast<char>(toupper(s[i]));
}

int	main(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
		while (argv[++i])
			print_upper(argv[i]);
	return (EXIT_SUCCESS);
}