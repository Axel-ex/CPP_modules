/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Axel <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 13:03:37 by Axel              #+#    #+#             */
/*   Updated: 2024/03/12 13:10:04 by Axel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <chrono>
#include <thread>

using	namespace std::chrono;

void	foo( void )
{
	std::this_thread::sleep_for(std::chrono::seconds(5));
}

int	main( void )
{
	auto	t0 = high_resolution_clock::now();
	foo();
	auto	t1 = high_resolution_clock::now();
	std::cout << duration_cast<milliseconds>(t1-t0).count() << std::endl;
}
