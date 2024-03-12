/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   esayfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 09:52:02 by achabrer          #+#    #+#             */
/*   Updated: 2024/02/29 11:18:18 by achabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iterator>

template<typename T>
int	easyfind( const T &cont, int to_find )
{
	typename T::const_iterator	pos;

	pos = std::find(cont.begin(), cont.end(), to_find);
	if (pos == cont.end())
		throw std::runtime_error("easyfind: no occurence was found");
	return (std::distance(cont.begin(), pos));
}