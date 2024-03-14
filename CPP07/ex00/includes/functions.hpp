/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 10:40:41 by achabrer          #+#    #+#             */
/*   Updated: 2024/03/12 16:03:14 by Axel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

template <typename T> void swap(T &a, T &b)
{
    T tmp;

    tmp = a;
    a = b;
    b = tmp;
}

template <typename T> const T &min(const T &a, const T &b)
{
    return (a < b ? a : b);
}

template <typename T> const T &max(const T &a, const T &b)
{
    return (a > b ? a : b);
}

#endif
