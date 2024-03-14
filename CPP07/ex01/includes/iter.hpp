/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 11:17:32 by achabrer          #+#    #+#             */
/*   Updated: 2024/02/28 11:48:41 by achabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

template <typename T> void iter(T *arr, size_t size, void (*f)(T &elem))
{
    for (size_t i = 0; i < size; i++)
        f(arr[i]);
}