/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 10:25:44 by achabrer          #+#    #+#             */
/*   Updated: 2024/02/27 15:09:18 by achabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScalarConverter.hpp"

// HELPER FCTS
static bool isChar(const std::string& str)
{
    return (str.size() == 1 && !std::isdigit(str[0]) && std::isprint(str[0]));
}

static bool isInt(const std::string& str)
{
    int idx = 0;

    if (str.find('-') != std::string::npos)
        idx++;
    for (int i = idx; i < str.size(); i++)
        if (!std::isdigit(str[i]))
            return (false);
    return (true);
}

static bool isFloat(const std::string& str)
{
    size_t dot = str.find(".");
    size_t f = str.find("f");
    size_t idx = 0;

    if (dot == std::string::npos || f == std::string::npos ||
        f != str.size() - 1)
        return (false);
    if (str.find('-') != std::string::npos)
        idx++;

    std::string left = str.substr(idx, dot - idx);
    std::string right = str.substr(dot + 1, f - dot);

    for (size_t i = idx; i < left.size(); i++)
        if (!std::isdigit(left[i]))
            return (false);
    for (size_t i = 0; i < right.size() - 1; i++)
        if (!std::isdigit(right[i]))
            return (false);

    return (left.size() > 0 && right.size() > 0);
}

static bool isDouble(const std::string& str)
{
    size_t dot = str.find(".");
    size_t sign = str.find("-");
    size_t idx = 0;

    if (dot == std::string::npos)
        return (false);
    if (sign != std::string::npos)
        idx++;

    std::string left = str.substr(idx, dot - idx);
    std::string right = str.substr(dot + 1, std::string::npos);

    for (size_t i = idx; i < left.size(); i++)
        if (!std::isdigit(left[i]))
            return (false);
    for (size_t i = dot + 1; i < right.size(); i++)
        if (!std::isdigit(right[i]))
            return (false);
    return (left.size() > 0 && right.size() > 0);
}

static bool isPseudo(const std::string& str)
{
    return (str == "nan" || str == "-inff" || str == "+inff" || str == "-inf" ||
            str == "+inf");
}

static void print(const std::string& str, long double nb)
{
    printChar(static_cast<char>(nb), str);
    printInt(static_cast<int>(nb), str);
    printFloat(static_cast<float>(nb), str);
    printDouble(static_cast<double>(nb), str);
}

// STATIC MEMBER
void ScalarConverter ::convert(const std::string& str)
{
    if (isChar(str))
        print(str, str[0]);
    else if (isInt(str))
        print(str, std::stoi(str.c_str()));
    else if (isFloat(str))
        print(str, std::strtof(str.c_str(), NULL));
    else if (isDouble(str))
        print(str, strtof(str.c_str(), NULL));
    else if (isPseudo(str))
        printPseudo(str);
    else
        std::cout << "other type detected" << std::endl;
}
