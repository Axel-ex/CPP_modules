/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 10:02:54 by achabrer          #+#    #+#             */
/*   Updated: 2024/03/15 12:29:13 by Axel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INCLUDE_INCLUDES_POINT_HPP_
#define INCLUDE_INCLUDES_POINT_HPP_

#include "Fixed.hpp"

class Point
{
    public:
        Point(void);
        Point(const Fixed& x, const Fixed& y);
        Point(const Point& src);
        ~Point(void);

        Point& operator=(const Point& rhs);
		bool operator==(const Point& rhs);

        Fixed getX(void) const;
        Fixed getY(void) const;

    private:
        const Fixed _x;
        const Fixed _y;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);
Fixed GetTriangleArea(Point a, Point b, Point c);

#endif
