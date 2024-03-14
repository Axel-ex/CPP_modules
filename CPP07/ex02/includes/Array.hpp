/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 11:53:25 by achabrer          #+#    #+#             */
/*   Updated: 2024/03/01 09:53:24 by achabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <typename T = int> class Array
{
    public:
        Array(void);
        Array(unsigned int n);
        Array(const Array &src);
        ~Array(void);

        Array &operator=(const Array<T> &rhs);
        T &operator[](int i);

        int size(void) const;

    private:
        T *_array;
        int _size;
};

#include "Array.tpp"

#endif
