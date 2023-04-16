/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_f.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammad <ahammad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 10:52:38 by ahammad           #+#    #+#             */
/*   Updated: 2023/04/15 17:32:40 by ahammad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "BitcoinExchange.hpp"
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


void check_value(float value)
{
    if (value < 0)
        throw std::invalid_argument("not a positive number.");
    if (value > 1000)
        throw std::invalid_argument("too large a number.");
}

std::string trim(const std::string &str)
{
    if (str.size() == 0)
        return str;
    size_t start = 0;
    size_t end = str.size();
    while (std::isspace(str[start]))
        ++start;
    while (std::isspace(str[end - 1]))
        --end;
    return str.substr(start, end);
} 

#include <ctime>

class Date
{
public:
    Date(std::string date)
        : _input(date)
    {
        struct tm tm;
        if (strptime(date.c_str(), "%Y-%m-%d", &tm))
        {
            this->_year = tm.tm_year + 1900;
            this->_month = tm.tm_mon + 1;
            this->_day = tm.tm_mday;
            this->_is_valid = true;
        }
        else
        {
            this->_is_valid = false;
        }
    }

    bool operator<(const Date &date) const
    {
        if (date._year > this->_year || date._month > this->_month || date._day > this->_day)
            return true;
        return false;
    }

    bool operator>(const Date &date) const
    {
        if (date._year < this->_year || date._month < this->_month || date._day < this->_day)
            return true;
        return false;
    }

    int year() const { return this->_year; }
    int month() const { return this->_month; }
    int day() const { return this->_day; }
    bool is_valid() const { return this->_is_valid; }
    std::string input() const { return this->_input; }

private:
    std::string _input;
    bool _is_valid;
    int _year;
    int _month;
    int _day;
};

std::map<Date, float, std::greater<Date> > parse_csv(const std::string &data_csv, char delimiter)
{
    std::ifstream file_csv(data_csv.c_str());
    if(file_csv.fail())
        throw std::invalid_argument("echec open file : " + data_csv);
    std::string line;
    std::map<Date, float, std::greater<Date> > values;
    std::getline(file_csv, line);
    while (std::getline(file_csv, line))
    {
        size_t virgule = line.find_first_of(delimiter);
        Date date = trim(line.substr(0, virgule));
        std::string value_str = trim(line.substr(virgule + 1));

        try 
        {
            float value;// = stof(value_str);
            sscanf(value_str.c_str(), "%f", &value);
            values.insert(std::make_pair(date, value));
        }
        catch (const std::invalid_argument &e) {
            throw std::runtime_error(data_csv + " ");
        }
    }
    return values;
}

void read_input(const std::string &filename, char delimiter)
{
    std::map<Date, float, std::greater<Date> > dateValues = parse_csv("data_c.csv", ','); //data.csv
    std::ifstream file(filename.c_str());
    if(file.fail())
        throw std::invalid_argument("echec open file : " + filename);
    std::string line;
    std::getline(file, line); 
    while (std::getline(file, line))
    {
        size_t virgule = line.find_first_of(delimiter);
        try {
            Date date = trim(line.substr(0, virgule));
			std::cout << "date.year() : " << date.year() << " date.day() : " << date.day() << std::endl;
            if (!date.is_valid())
                throw std::invalid_argument("bad input => " + date.input());
            std::string value_str = trim(line.substr(virgule + 1));
            float value;
            sscanf(value_str.c_str(), "%f", &value);
            check_value(value);

            float valueresult = std::numeric_limits<float>::max();

            std::map<Date, float, std::greater<Date> >::iterator find_date = dateValues.find(date); //input.txt
            std::cout << "value input : " << value << std::endl;
            std::cout << "date input : " << date.year() << date.month() << date.day()<< std::endl;
            
            if (find_date == dateValues.end())
            {
                std::map<Date, float, std::greater<Date> >::iterator result;
                result = dateValues.lower_bound(date);
                std::cout << "RESULT : " << result->second << std::endl;
                if (result != dateValues.end())
                    valueresult = result->second * value;
            }
            else
            {
                valueresult = find_date->second * value;
            }
            std::cout << "value data.csv : " << find_date->second << std::endl;
    
			std::cout << std::setw(2) << std::setfill('0') << date.year();
			std::cout << '-';
			std::cout << std::setw(2) << std::setfill('0') << date.month();
			std::cout << '-';
			std::cout << std::setw(2) << std::setfill('0') << date.day();
            std::cout /*<< date.input()*/ << " => " << value << " = " << valueresult /*value ou result*/<< std::endl;
        }
        catch (const std::invalid_argument &e) {
            std::cout << "Error: " << e.what() << std::endl;
        }
    }
}

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        std::cout << "need input.txt on argument" << std::endl;
        return (0);
    }
    try
    {
        read_input(argv[1], '|');
    }
    catch (const std::invalid_argument &e)
    {
        std::cerr << "Error: bad: "<< e.what() << std::endl;
    }
    catch (const std::runtime_error &e)
    {
        std::cerr << "Error: bad: "<< e.what() << std::endl;
    }
    return 0;
}
