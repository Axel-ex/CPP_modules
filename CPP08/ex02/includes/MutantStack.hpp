/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 09:47:36 by achabrer          #+#    #+#             */
/*   Updated: 2024/05/30 15:35:32 by achabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <deque>
#include <iostream>
#include <list>
#include <stack>

/**
 * @brief container adaptor making stack iterable
 *
 * The stack itself is a container adaptor that restrict the underlying
 * sequential container to LIFO structure. by default the underlying container
 * is assigned to deque if no arg provided.
 *
 * @tparam T type the container is managing
 * @tparam C stack underlying container
 */
template <typename T, typename C = std::deque<T> >
class MutantStack : public std::stack<T, C>
{
    public:
        MutantStack(void);
        MutantStack(const MutantStack& src);
        ~MutantStack(void);

        MutantStack& operator=(const MutantStack& rhs);

        typedef typename C::iterator iterator;
        iterator begin(void);
        iterator end(void);
};

#include "MutantStack.tpp"

#endif
