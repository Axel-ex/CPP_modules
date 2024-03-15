/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 15:15:34 by achabrer          #+#    #+#             */
/*   Updated: 2024/02/19 10:02:03 by achabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"

const int Fixed::_bits = 8;

Fixed ::Fixed(void) : _val(0) {}

Fixed ::Fixed(const int value) { this->_val = value * (1 << Fixed::_bits); }

Fixed ::Fixed(const float value) { this->_val = value * (1 << Fixed::_bits); }

Fixed ::Fixed(const Fixed& to_copy) : _val(to_copy._val) {}

Fixed ::~Fixed(void) {}

int Fixed::getRawBits() const { return (this->_val); }

void Fixed::setRawBits(int const raw) { this->_val = raw; }

float Fixed ::toFloat(void) const
{
    return ((float)this->_val / (float)(1 << Fixed::_bits));
}

int Fixed ::toInt(void) const { return (this->_val >> Fixed::_bits); }

// OPERATOR OVERLOAD
Fixed& Fixed::operator=(const Fixed& to_copy)
{
    if (this != &to_copy)
        this->_val = to_copy._val;
    return (*this);
}

bool Fixed ::operator>(const Fixed& fixed) const
{
    return (this->_val > fixed.getRawBits());
}

bool Fixed ::operator>=(const Fixed& fixed) const
{
    return (this->_val >= fixed.getRawBits());
}

bool Fixed ::operator<(const Fixed& fixed) const
{
    return (this->_val < fixed.getRawBits());
}

bool Fixed ::operator<=(const Fixed& fixed) const
{
    return (this->_val <= fixed.getRawBits());
}

bool Fixed ::operator==(const Fixed& fixed) const
{
    return (this->_val == fixed.getRawBits());
}

bool Fixed ::operator!=(const Fixed& fixed) const
{
    return (this->_val != fixed.getRawBits());
}

Fixed Fixed ::operator+(const Fixed& fixed)
{
    return (Fixed(this->toFloat() + fixed.toFloat()));
}

Fixed Fixed ::operator-(const Fixed& fixed)
{
    return (Fixed(this->toFloat() - fixed.toFloat()));
}

Fixed Fixed ::operator*(const Fixed& fixed)
{
    return (Fixed(this->toFloat() * fixed.toFloat()));
}

Fixed Fixed ::operator/(const Fixed& fixed)
{
    return (Fixed(this->toFloat() / fixed.toFloat()));
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed)
{
    out << fixed.toFloat();
    return (out);
}

Fixed& Fixed::operator++(void)
{
    this->_val++;
    return (*this);
}

Fixed Fixed::operator++(int dummy)
{
    Fixed old = Fixed(*this);

    (void)dummy;
    this->_val++;
    return (old);
}

Fixed& Fixed::operator--(void)
{
    this->_val--;
    return (*this);
}

Fixed Fixed::operator--(int dummy)
{
    Fixed old = Fixed(*this);

    (void)dummy;
    this->_val--;
    return (old);
}

// STATIC METHOD
Fixed& Fixed::min(Fixed& nb1, Fixed& nb2) { return (nb1 > nb2 ? nb2 : nb1); }

const Fixed& Fixed::min(const Fixed& nb1, const Fixed& nb2)
{
    return (nb1 > nb2 ? nb2 : nb1);
}

Fixed& Fixed::max(Fixed& nb1, Fixed& nb2) { return (nb1 > nb2 ? nb1 : nb2); }

const Fixed& Fixed::max(const Fixed& nb1, const Fixed& nb2)
{
    return (nb1 > nb2 ? nb1 : nb2);
}