/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 15:12:22 by achabrer          #+#    #+#             */
/*   Updated: 2024/02/16 13:58:25 by achabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED__HPP
#define FIXED__HPP

#include <iostream>

class Fixed
{
	public:
		Fixed( void );
		Fixed( const int value);
		Fixed( const float value);
		Fixed( const Fixed &to_copy);
		~Fixed( void );
		
		Fixed &operator=(const Fixed &to_copy);

		int		getRawBits( void ) const;
		void 	setRawBits( int const raw );
		float	toFloat( void ) const;
		int		toInt( void ) const ;

	private:
		int	_val;
		static const int	_bits;
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif