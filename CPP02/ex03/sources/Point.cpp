/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 10:07:07 by achabrer          #+#    #+#             */
/*   Updated: 2024/02/19 10:31:43 by achabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Point.hpp"

//CONSTRUCOR / DESTRUCTOR
Point::Point( void ) : _x(0), _y(0)
{}

Point::~Point( void )
{}

Point::Point( const float x, const float y ) : _x(x), _y(y)
{}

//COPY
Point::Point( const Point &point ) : _x(point.getX()), _y(point.getY())
{}

Point	&Point::operator=(const Point &point)
{
	if (this != &point)
	{
		_x = point.getX();
		_y = point.getY();
	}
	return (*this);
}

Fixed	Point::getX( void ) const
{
	return (_x);
}

Fixed Point::getY( void ) const
{
	return (_y);
}

