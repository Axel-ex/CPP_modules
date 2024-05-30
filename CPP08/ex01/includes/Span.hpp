/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 11:45:44 by achabrer          #+#    #+#             */
/*   Updated: 2024/05/30 15:17:29 by achabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>

class Span
{
    public:
        Span(void);
        Span(unsigned int N);
        Span(const Span& src);
        ~Span(void);

        Span& operator=(const Span& rhs);

        void setMax(unsigned int max);
        int getElement(unsigned int idx) const;
        int getSize(void) const;
        int min(void) const;
        int max(void) const;

        void addNumber(int to_add);
        int shortestSpan(void) const;
        int longestSpan(void) const;
        void fill(void);

        class FullSpanException : public std::exception
        {
                virtual const char* what(void) const throw();
        };

        class NoSpanException : public std::exception
        {
                virtual const char* what(void) const throw();
        };

    private:
        unsigned int _N;
        std::vector<int> _array;
};

std::ostream& operator<<(std::ostream& ofs, const Span& rhs);

#endif
