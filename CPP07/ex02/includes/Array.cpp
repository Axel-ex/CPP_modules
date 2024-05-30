/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 14:56:38 by achabrer          #+#    #+#             */
/*   Updated: 2024/05/30 11:29:49 by achabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Array.hpp"

template <typename T> Array<T>::Array(void) : _size(0) {}

template <typename T> Array<T>::Array(unsigned int n) : _array(NULL), _size(n)
{
    _array = new T[n];
	for (unsigned int i = 0; i < n; i++)
		_array[i] = T();
}

template <typename T> Array<T>::Array(const Array<T>& src) { *this = src; }

template <typename T> Array<T>::~Array(void) { delete[] _array; }

// OPERATOR OVERLOAD
template <typename T> Array<T>& Array<T>::operator=(const Array<T>& rhs)
{
    if (this == &rhs)
        return (*this);

    if (_array)
        delete[] _array;
    _size = rhs._size;
    _array = new T[_size];
    for (int i = 0; i < _size; i++)
        _array[i] = rhs._array[i];

    return (*this);
}

template <typename T> T& Array<T>::operator[](int i)
{
    if (i > _size - 1 || i < 0)
        throw std::out_of_range("index out of range");
    return (_array[i]);
}

// FUNCTION MEMBERS
template <typename T> int Array<T>::size(void) const { return (_size); }
