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

	/*std::ofstream operator<<(const Date &date) const
	{
		std::string dat_tmp;
		dat_tmp += "_years : " ; 
		dat_tmp += _year;
		dat_tmp += " _month : " ; 
		dat_tmp += _month;
		dat_tmp += " _day : " ; 
		dat_tmp += _day;
		dat_tmp += " _input : " ; 
		dat_tmp += _input;
		dat_tmp += " _is_valid : " ; 
		dat_tmp += _is_valid;
		return (std::ofstream)(dat_tmp);
	}*/

    bool operator<(const Date &date) const
    {
        if (this->_input < date._input)// || this->_month < date._month || this->_day < date._day)
            return true;
        return false;
    }

    bool operator>(const Date &date) const
    {
        if (this->_input > date._input) // || this->_month > date._month || this->_day > date._day)
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
        if (date_csv._input < date_txt._input)// || date_csv.month() < date_txt.month() || date_csv.day() < date_txt.day())
		{            
			std::cout << "if operator true : " << date_csv._input << "|| " << date_txt._input << std::endl;
			return true;
		}
			std::cout << "if operator false : " << date_csv._input << "|| " << date_txt._input << std::endl;

        return false;
    }
};


	/*bool compare(const Date &date_csv, const Date &date_txt)
    {
        if (date_csv.year() < date_txt.year() || date_csv.month() < date_txt.month() || date_csv.day() < date_txt.day())
            return true;
        return false;
    }*/

void	print_map(std::map<Date, float, compare> printed_map)
{
	std::map<Date, float, compare>::iterator it = printed_map.begin();
	std::map<Date, float, compare>::iterator ite = printed_map.end();
	while (it != ite)
	{
		std::cout<<"it->first : " << (it)->first._year <<(it)->first._month << (it)->first._day<< " it->second : " << it->second <<std::endl;
		it++;
	}
}

    // bool operator>(const Date &date_csv, const Date &date_txt)
    // {
    //     if (date_csv.year() > date_txt.year() || date_csv.month() > date_txt.month() || date_csv.day() > date_txt.day())
    //         return true;
    //     return false;
    // }

std::map<Date, float, compare> parse_csv(const std::string &data_csv, char delimiter)
{
    std::ifstream file_csv(data_csv.c_str());
    if(file_csv.fail())
        throw std::invalid_argument("fail open file : " + data_csv);
    std::string line;
    std::map<Date, float, compare> values;
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
    std::cout /*<< date.input()*/ << " => " << value << " = " << "PAS DE VALEUR "<< std::endl;
	}

void print_value(float value, float valueresult)
	{
    std::cout /*<< date.input()*/ << " => " << value << " = " << valueresult /*value ou result*/<< std::endl;
	}

void read_input(const std::string &filename, char delimiter)
{
    std::map<Date, float, compare> dateValues = parse_csv("data_c.csv", ','); //data.csv
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
			std::cout << "date.year() : " << date.year() << "date.year() : " << date.month() <<" date.day() : " << date.day() << std::endl;
            if (!date.is_valid())
                throw std::invalid_argument("bad input => " + date.input());
            std::string value_str = trim(line.substr(virgule + 1));
            float value;
            sscanf(value_str.c_str(), "%f", &value);
            check_value(value);

            float valueresult = std::numeric_limits<float>::max();

            std::map<Date, float, compare>::iterator find_date = dateValues.upper_bound(date); //input.txt
            //std::cout << "value input : " << value << std::endl;
            //std::cout << "date input : " << date.year() << date.month() << date.day()<< std::endl;
            if (find_date == dateValues.end())
            {
				//print_map(dateValues);    
				//std::cout<< "IF" << std::endl;
                //std::map<Date, float >::iterator result;
				print_map(dateValues);
				print_date(date);
				print_value(value);
                //result = dateValues.lower_bound(date);
				//std::cout << "RESULT : " << result->second << std::endl;
/*                if (result != dateValues.end())
                {
					valueresult = result->second * value;
					print_date(date);
					print_value(value, valueresult); 
				}
				else
				{
					std::cout << "HERE" << std::endl;
					print_date(date);
					print_value(value);*/
					//std::cout << "pas date trouver" << std::endl;
//				}
				//std::cout << "valueresult_IF : " <<valueresult << std::endl;
            }
            else
            {
				//std::cout<< "ELSE" << std::endl;
				std::cout << "find_date : " << find_date->first._input <<std::endl;
                valueresult = find_date->second * value;
	            //std::cout << "valueresult_ELSE : " <<valueresult << std::endl;
				print_date(date);
				print_value(value, valueresult); 
            }
            //std::cout << "VALUE : " << value << std::endl;
			//std::cout << "find_date->first" << find_date->first << std::endl;; //operator<<
			if (find_date != dateValues.end())
            	std::cout << "value data.csv : " << find_date->second << std::endl;

		/*print_date(date);
		print_value(value, valueresult);
		print_value(value);*/
		//print_map(dateValues);    
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
	else if  (argc != 2)
	{
		std::cout << "just need input.txt" << std::endl;
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


//date en string
//map trier clef en string (date) sans la classe date
//compare en string avec input
//upper ou lower a verifier 