/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 13:12:56 by achabrer          #+#    #+#             */
/*   Updated: 2024/03/09 09:15:20 by achabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/BitcoinExchange.hpp"

BitcoinExchange ::BitcoinExchange(void) { loadDataBase(); }

BitcoinExchange ::BitcoinExchange(const std::string &file) : _file_name(file)
{
    loadDataBase();
}

BitcoinExchange ::BitcoinExchange(const BitcoinExchange &src) { *this = src; }

BitcoinExchange ::~BitcoinExchange(void) {}

// OPERATOR OVERLOAD
BitcoinExchange &BitcoinExchange ::operator=(const BitcoinExchange &rhs)
{
    if (this != &rhs)
    {
        _data = rhs._data;
        _file_name = rhs._file_name;
    }
    return (*this);
}

// MEMBER FCT
void BitcoinExchange ::loadDataBase(void)
{
    std::ifstream ifs;
    std::string row;
    std::pair<std::time_t, float> curr;

    ifs.open("data/data.csv", std::ios::in);
    if (ifs.fail())
        throw std::ifstream::failure("Error: database not found");

    std::getline(ifs, row, '\n');
    while (std::getline(ifs, row, '\n'))
    {
        curr.first = strToTime(row.substr(0, row.find(',')));
        curr.second =
            std::strtof(row.substr(row.find(',') + 1).c_str(), nullptr);
        _data.insert(curr);
    }
    ifs.close();
}

void BitcoinExchange ::compute(void)
{
    std::ifstream ifs;
    std::string line;
    std::string date;
    std::string value;

    ifs.open(_file_name);
    if (ifs.fail())
        throw std::ifstream::failure("Error: could not open the file " +
                                     _file_name);
    std::getline(ifs, line, '\n');
    while (std::getline(ifs, line, '\n'))
    {
        date = line.substr(0, line.find(" |"));
        value = line.substr(line.find('|') + 1);
        processLine(date, value);
    }
    ifs.close();
}

void BitcoinExchange ::processLine(const std::string &date,
                                   const std::string &value)
{
    float num_value = std::strtof(value.c_str(), nullptr);
    float match;

    if (value == date || !isDateFormat(date))
        return (LOG_ERR(BAD_INPUT + date), void());
    if (num_value < 0)
        return (LOG_ERR(NEGATIVE_NB), void());
    match = _data[matchDate(date)];
    if (num_value * match > INT_MAX)
        return (LOG_ERR(LARGE_NB), void());

    std::cout << date << " => " << value << " = " << match * num_value
              << std::endl;
}

std::time_t BitcoinExchange::matchDate(const std::string &date) const
{
    std::map<std::time_t, float>::const_iterator it = _data.begin();
    std::time_t value = strToTime(date);

    if (it->first >= value)
        return (it->first);
    for (; it != _data.end(); ++it)
    {
        if (it->first >= value)
            return (std::prev(it)->first);
    }
    return (_data.rbegin()->first);
}

// HELPER FCT
std::time_t BitcoinExchange::strToTime(const std::string &str) const
{
    std::tm tm = {};
    std::stringstream date(str);

    date >> std::get_time(&tm, "%Y-%m-%d");

    return (mktime(&tm));
}

std::string BitcoinExchange ::timeToStr(const time_t &time) const
{
    std::tm *tm = std::localtime(&time);
    char buffer[20];

    std::strftime(buffer, sizeof(buffer), "%Y-%m-%d", tm);

    return (std::string(buffer));
}

/**
 * @brief  check if the date is well formated
 *
 * if the date is not properly formatted, converting it to a time_t and then
 * back to a string will yield a different string (mktime interprets the date if
 * wrong input is provided)
 *
 * @param date
 */
bool BitcoinExchange::isDateFormat(const std::string &date) const
{
    std::string res = timeToStr(strToTime(date));
    return (date == res);
}
