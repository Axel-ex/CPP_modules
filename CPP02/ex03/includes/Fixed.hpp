/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 15:12:22 by achabrer          #+#    #+#             */
/*   Updated: 2024/02/19 09:48:12 by achabrer         ###   ########.fr       */
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
		
		Fixed	&operator=( const Fixed &to_copy );
		bool	operator>( const Fixed &fixed ) const;
		bool	operator>=( const Fixed &fixed ) const;
		bool	operator<( const Fixed &fixed ) const;
		bool	operator<=( const Fixed &fixed ) const;
		bool	operator==( const Fixed &fixed ) const;
		bool	operator!=( const Fixed &fixed ) const;
		Fixed	operator+( const Fixed &fixed );
		Fixed	operator-( const Fixed &fixed );
		Fixed	operator*( const Fixed &fixed );
		Fixed	operator/( const Fixed &fixed );
		Fixed	&operator++( void );
		Fixed	operator++( int dummy );
		Fixed	&operator--( void );
		Fixed	operator--(int dummy);

		int		getRawBits( void ) const;
		void 	setRawBits( int const raw );
		float	toFloat( void ) const;
		int		toInt( void ) const ;

		static const Fixed &min(const Fixed &nb1, const Fixed &nb2);
		static const Fixed &max(const Fixed &nb1, const Fixed &nb2);
		static Fixed &min(Fixed &nb1, Fixed &nb2);
		static Fixed &max(Fixed &nb1, Fixed &nb2);

	private:
		int	_val;
		static const int	_bits;
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif