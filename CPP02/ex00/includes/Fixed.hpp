/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 15:12:22 by achabrer          #+#    #+#             */
/*   Updated: 2024/02/15 16:13:11 by achabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED__HPP
#define FIXED__HPP

#include <iostream>

class Fixed
{
    public:
        Fixed(void);
        Fixed(const Fixed &to_copy);
        Fixed &operator=(const Fixed &to_copy);
        ~Fixed(void);

        int getRawBits(void) const;
        void setRawBits(int const raw);

    private:
        int _val;
        static const int _bits;
};

#endif