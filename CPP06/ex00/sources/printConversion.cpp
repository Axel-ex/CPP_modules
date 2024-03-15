/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printConversion.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 10:47:40 by achabrer          #+#    #+#             */
/*   Updated: 2024/02/27 18:20:34 by achabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScalarConverter.hpp"

static bool overflow(e_type type, const std::string& str)
{
    long double value = std::strtold(str.c_str(), NULL);

    switch (type)
    {
    case CHAR:
        return (value < std::numeric_limits<char>::min() ||
                value > std::numeric_limits<char>::max());
    case INT:
        return (value < std::numeric_limits<int>::min() ||
                value > std::numeric_limits<int>::max());
    case FLOAT:
        return (value < std::numeric_limits<float>::min() &&
                value > std::numeric_limits<float>::max());
    case DOUBLE:
        return (value < std::numeric_limits<double>::min() &&
                value > std::numeric_limits<double>::max());
    default:
        return (false);
    }
}

void printChar(char c, const std::string& str)
{
    if (overflow(CHAR, str))
        return (std::cout << "char overflow" << std::endl, void());
    if (std::isprint(c))
        std::cout << "char: " << c << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;
}

void printInt(int i, const std::string& str)
{
    if (overflow(INT, str))
        return (std::cout << "int overflow" << std::endl, void());
    std::cout << "int: " << i << std::endl;
}

void printFloat(float f, const std::string& str)
{
    if (overflow(FLOAT, str))
        return (std::cout << "float overflow" << std::endl, void());
    std::cout << "float: " << f << "f" << std::endl;
}

void printDouble(double d, const std::string& str)
{
    if (overflow(DOUBLE, str))
        return (std::cout << "double overflow" << std::endl, void());
    std::cout << "double value: " << d << std::endl;
}

void printPseudo(const std::string& str)
{
    char sign = '+';
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;

    if (str.find('-') != std::string::npos)
        sign = '-';
    if (str.find("inf") != std::string::npos)
    {
        std::cout << "float: " << sign << "inff" << std::endl;
        std::cout << "double: " << sign << "inf" << std::endl;
    }
    else
    {
        std::cout << "float: nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
    }
}