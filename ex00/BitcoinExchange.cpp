/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammad <ahammad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 17:55:05 by ahammad           #+#    #+#             */
/*   Updated: 2023/04/29 21:11:13 by ahammad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>
#include <string>

size_t     ft_cmpt_point(std::string value_str)
{
	size_t i = 0;
	
	size_t point = 0; 
	while (i < value_str.length())
	{
		if (value_str[i] == '.')
		{
			++point;
		}
		++i;
 	}
	std::cout << " point : " << point << std::endl;
	return (point);
}

bool	check_string_value(std::string value_str)
{
	std::string chars_list = "0123456789.";

	size_t found = value_str.find_first_not_of(chars_list);
	
	if(found == std::string::npos)
	{
		return (true);
	}
	else
		return (false);
}


void 	check_value(float value)
{

    //utliser is digit //compter les symboles
    std::cout << "value : " << value << std::endl;
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

void print_date(Date date)
{
	std::cout << std::setw(2) << std::setfill('0') << date.year();
	std::cout << '-';
	std::cout << std::setw(2) << std::setfill('0') << date.month();
	std::cout << '-';
	std::cout << std::setw(2) << std::setfill('0') << date.day();
}

void print_value(float value)
{
    std::cout << " => " << value << " = " << "PAS DE VALEUR "<< std::endl;
}

void print_value(float value, float valueresult)
{
    std::cout << " => " << value << " = " << valueresult<< std::endl;
}

void read_input(const std::string &filename, char delimiter)
{
    std::map<Date, float, compare> dateValues = parse_csv("data.csv", ',');
    std::ifstream file(filename.c_str());
    if(file.fail())
        throw std::invalid_argument("fail open file : " + filename);
    std::string line;
    std::getline(file, line); 
    while (std::getline(file, line))
    {
        size_t virgule = line.find_first_of(delimiter);
        try {
            Date date = trim(line.substr(0, virgule));
            //std::cout << "this->_year : " << date.year() << " this->_month : " << date.month() << " this->_day : " << date.day() << std::endl;
            //if (date.year() == 2020)
                
            /*if (date.year() % 4 != 0 && date.month() == 2 && date.day() > 28)
            {
                date.is_valid() = false;
            }*/
            if (!date.is_valid())
                throw std::invalid_argument("bad input => " + date.input());
            std::string value_str = trim(line.substr(virgule + 1));
            //std::cout << "this->_year : date " << date.year() << " this->_month : " << date.month() << "this->_day : " << date.day() << std::endl;
            float value;
            sscanf(value_str.c_str(), "%f", &value);

			std::cout << "value_str : " <<  value_str << std::endl;
			int cmp_point;
			cmp_point = ft_cmpt_point(value_str);
			bool checking_value;
			checking_value = check_string_value(value_str);
			std::cout << "checking_value : " <<  checking_value << " cmp_point : " << cmp_point << std::endl;

			if (checking_value == 0 || cmp_point > 1)
				throw std::invalid_argument("bad value : " + value_str);

			
            std::cout << "  value_str : " << value_str << std::endl;
            if (date.is_valid())
				check_value(value);
            std::cout << "  value_str : " << value_str << std::endl;
     
            //verifie si 0123456789 et juste seulement un "."            

            float valueresult = std::numeric_limits<float>::max();

            std::map<Date, float, compare>::iterator find_date = dateValues.lower_bound(date); //input.txt
            if (find_date == dateValues.end())
            {
				print_map(dateValues);
				print_date(date);
				print_value(value);
            }
            else
            {
                valueresult = find_date->second * value;
				print_date(date);
				print_value(value, valueresult); 
            }
			if (find_date != dateValues.end())
            	std::cout << "value data.csv : " << find_date->second << std::endl;
 
		}
        catch (const std::invalid_argument &e) {
            std::cout << "Error: " << e.what() << std::endl;
        }
    }
}