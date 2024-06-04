/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 10:16:43 by achabrer          #+#    #+#             */
/*   Updated: 2024/06/04 10:27:19 by achabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctime>
#include <cstdio>

bool get_time(const std::string& date_str, std::tm& tm) {
    int year, month, day;
    if (sscanf(date_str.c_str(), "%4d-%2d-%2d", &year, &month, &day) != 3) {
        return false; // Parsing failed
    }
    tm.tm_year = year - 1900; // tm_year is years since 1900
    tm.tm_mon = month - 1;    // tm_mon is 0-based
    tm.tm_mday = day;
    return true;
}
