/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 10:07:07 by achabrer          #+#    #+#             */
/*   Updated: 2024/03/15 13:20:13 by Axel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Point.hpp"

Point::Point(void) : _x(0), _y(0) {}

Point::Point(const Fixed& x, const Fixed& y) : _x(x), _y(y) {}

Point::Point(const Point& src) { *this = src; }

Point::~Point(void) {}

Point& Point::operator=(const Point& rhs)
{
    if (this != &rhs)
    {
        const_cast<Fixed&>(_x) = rhs._x;
        const_cast<Fixed&>(_y) = rhs._y;
    }
    return (*this);
}

bool Point::operator==(const Point& rhs)
{
    return (_x == rhs._x && _y == rhs._y);
}

Fixed Point::getX(void) const { return _x; }
Fixed Point::getY(void) const { return _y; }
