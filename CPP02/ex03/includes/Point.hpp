/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 10:02:54 by achabrer          #+#    #+#             */
/*   Updated: 2024/02/19 10:31:13 by achabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	POINT__HPP
#define POINT__HPP

#include <iostream>
#include "Fixed.hpp"

class Point
{
	public:
		Point( void );
		Point( const float x, const float y);
		Point( const Point &point);
		~Point( void );

		Point	&operator=(const Point &point);
		Fixed	getX( void ) const;
		Fixed	getY( void ) const;

	private:
		Fixed	_x;
		Fixed	_y;
};

#endif