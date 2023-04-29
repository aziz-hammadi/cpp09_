/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammad <ahammad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 17:55:05 by ahammad           #+#    #+#             */
/*   Updated: 2023/04/29 21:14:59 by ahammad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BitcoinExchange_HPP
#define BitcoinExchange_HPP

#include <iostream>
#include <fstream> 
#include <string>
#include <map>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <iomanip>
#include <limits>
#include <algorithm>
#include <ctime>


class Date
{
public:
    Date(std::string date)
        : _input(date)

    {
        struct tm tm;
		char *ret = strptime(date.c_str(), "%Y-%m-%d", &tm);
        if (ret && *ret == '\0')
        {
            this->_year = tm.tm_year + 1900;
            this->_month = tm.tm_mon + 1;
            this->_day = tm.tm_mday;
            this->_is_valid = true;
            if (_year % 4 != 0 && _month == 2 && _day > 28)
            {
                this->_is_valid = false;
            }
            if (((_month >= 3 && _month <= 7) && (_month % 2 == 0) && _day > 30) || ((_month >= 8 && _month <= 12) && (_month % 2 != 0) && _day > 30)) 
            {
                this->_is_valid = false;
            }
        }
        //std::cout << "this->_year : " << date.year() << " this->_month : " << date.month() << "this->_day : " << date.day() << std::endl;
        else
        {
            this->_is_valid = false;
        }
    }

    bool operator<(const Date &date) const
    {
        if (this->_input < date._input)
            return true;
        return false;
    }

    bool operator>(const Date &date) const
    {
        if (this->_input > date._input)
            return true;
        return false;
    }

    int year() const { return this->_year; }
    int month() const { return this->_month; }
    int day() const { return this->_day; }
    bool is_valid() const { return this->_is_valid; }
    std::string input() const { return this->_input; }

public:
    std::string _input;
    bool _is_valid;
    int _year;
    int _month;
    int _day;
};

struct compare 
{
    bool operator()(const Date& date_csv, const Date& date_txt) const
	{
        if (date_csv._input > date_txt._input)// || date_csv.month() < date_txt.month() || date_csv.day() < date_txt.day())
		{            
			//std::cout << "if operator true : " << date_csv._input << "|| " << date_txt._input << std::endl;
			return true;
		}
			//std::cout << "if operator false : " << date_csv._input << "|| " << date_txt._input << std::endl;

        return false;
    }
};

size_t  ft_cmpt_point(std::string value_str);
bool    check_string_value(std::string value_str);
void    check_value(float value);
std::string trim(const std::string &str);
void    print_map(std::map<Date, float, compare> printed_map);
void    print_date(Date date);
void    print_value(float value);
void    print_value(float value, float valueresult);
void    read_input(const std::string &filename, char delimiter);
std::map<Date, float, compare> parse_csv(const std::string &data_csv, char delimiter);


#endif