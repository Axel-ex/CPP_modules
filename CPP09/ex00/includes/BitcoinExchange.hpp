/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 11:46:13 by achabrer          #+#    #+#             */
/*   Updated: 2024/06/04 12:56:34 by achabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <ctime>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>

#define INT_MAX 2147483648

#define LOG_ERR(str) std::cerr << str << std::endl

#define FILE_NT_FND "Error: could not open the file"
#define LARGE_NB "Error: too large a number."
#define BAD_INPUT "Error: bad input => "

class BitcoinExchange
{
    private:
        std::map<std::time_t, float> _data;
        std::string _file_name;

    public:
        BitcoinExchange(void);
        BitcoinExchange(const std::string& file);
        BitcoinExchange(const BitcoinExchange& src);
        ~BitcoinExchange(void);

        BitcoinExchange& operator=(const BitcoinExchange& rhs);

        void compute(void);
        void loadDataBase(void);
        void processLine(const std::string& str, const std::string& value);

        std::time_t strToTime(const std::string& str) const;
        std::string timeToStr(const std::time_t& time) const;
        std::time_t matchDate(const std::string& date) const;
        bool isDateFormat(const std::string& date) const;
};

bool get_time(const std::string& date_str, std::tm& tm);

template <typename Iterator>
Iterator my_prev(Iterator it) {
    return --it;
}

#endif
