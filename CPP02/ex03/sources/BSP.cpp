/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BSP.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 10:34:05 by achabrer          #+#    #+#             */
/*   Updated: 2024/03/15 13:26:34 by Axel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Point.hpp"
#include <cstdlib>

static Fixed abs(Fixed f) { return (f = f < 0 ? f * -1 : f); }

/*Area A = ABS [ x1(y2 – y3) + x2(y3 – y1) + x3(y1-y2) ] / 2 */
Fixed GetTriangleArea(Point a, Point b, Point c)
{
    Fixed area;

    area = ((a.getX() * (b.getY() - c.getY())) +
            (b.getX() * (c.getY() - a.getY())) +
            (c.getX() * (a.getY() - b.getY()))) /
           2;
    return (abs(area));
}

bool bsp(Point const a, Point const b, Point const c, Point const p)
{
    Fixed ABC = GetTriangleArea(a, b, c);

    Fixed PAB = GetTriangleArea(p, a, b);
    Fixed PAC = GetTriangleArea(p, a, c);
    Fixed PCB = GetTriangleArea(p, b, c);

    bool is_within = (ABC == (PAB + PAC + PCB));
	/* Colinear points -> Area = 0 */
    bool is_on_edge = PAB.toFloat() && PAC.toFloat() && PCB.toFloat();

    return (is_within && is_on_edge);
}
