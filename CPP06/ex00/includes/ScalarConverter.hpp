/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 17:22:23 by achabrer          #+#    #+#             */
/*   Updated: 2024/02/27 13:39:39 by achabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>

typedef enum s_type
{
    CHAR,
    INT,
    FLOAT,
    DOUBLE

} e_type;

class ScalarConverter
{
    public:
        static void convert(const std::string& str);
};

void printChar(char c, const std::string& str);
void printInt(int i, const std::string& str);
void printFloat(float f, const std::string& str);
void printDouble(double d, const std::string& str);
void printPseudo(const std::string& str);

#endif