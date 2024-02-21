/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radomChump.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 16:25:04 by achabrer          #+#    #+#             */
/*   Updated: 2024/01/26 16:25:20 by achabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

void	randomChump( std::string name)
{
	Zombie zombie = Zombie(name);
	zombie.announce();
}