/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BSP.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 10:34:05 by achabrer          #+#    #+#             */
/*   Updated: 2024/03/15 13:20:02 by Axel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Point.hpp"
#include <cstdlib>
/*

Input: A = (0, 0), B = (10, 30), C = (20, 0), P(10, 15)
Output: Inside
Explanation:
              B(10,30)
                / \
               /   \
              /     \
             /   P   \      P'
            /         \
     A(0,0) ----------- C(20,0)

Input: A = (0, 0), B = (10, 30), C = (20, 0), P(30, 15)
Output: Outside
Explanation:
              B(10,30)
                / \
               /   \
              /     \
             /       \      P
            /         \
     A(0,0) ----------- C(20,0)

Solution:
Let the coordinates of three corners be (x1, y1), (x2, y2) and (x3, y3). And
coordinates of the given point P be (x, y)

Calculate area of the given triangle, i.e., area of the triangle ABC in the
above diagram. Area A = [ x1(y2 – y3) + x2(y3 – y1) + x3(y1-y2) ] / 2 Calculate
area of the triangle PAB. We can use the same formula for this. Let this area be
A1. Calculate area of the triangle PBC. Let this area be A2. Calculate area of
the triangle PAC. Let this area be A3. If P lies inside the triangle, then A1 +
A2 + A3 must be equal to A.
*/

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
    bool is_on_edge = PAB.toFloat() && PAC.toFloat() && PCB.toFloat();

    return (is_within && is_on_edge);
}
