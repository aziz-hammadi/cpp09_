/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammad <ahammad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 10:52:38 by ahammad           #+#    #+#             */
/*   Updated: 2023/04/13 17:34:32 by ahammad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream> 
//#include <strstream>
#include <string>
#include <map>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <iomanip>

/*
int check_day(std::string day) //inutile
{
    int nbr_day;
    nbr_day = atoi(day);
    if (nbr_day < 1 || nbr_day > 31)
        trow std::invalid_argument("Date malformé");
    return (1);
}
*/
/*
int check_mouth(std::string mouth)
{
    int nbr_mouth;
    nbr_mouth = atoi(mouth)
    if(mouth < 1 || mouth > 12)
        return (0)
    return (1);
}

int check_year(std::string year)
{
    int nbr_year;
    nbr_year = atoi(year);
    if(nbr_year < 2009 || nbr_year > 2023)
        return (0)
    return (1);
}*/
// bool check_value_date(string::string date) //la nouvelle version check date
// {
//     struct tm tm;
//     if (strptime(date.c_str(), "%Y-%m-%d", &tm))
// 		return (true);
//     else if("%m" < 2009)
// 	{
// 		std::cout << "Error: bad input invalid mouth (%m < 2009)=> "<< date << std::endl;
// 		return (false);  
// 	}
// 	else
// 	{
// 		std::cout << "Error: invalid date. => "<< date << std::endl;
// 		return (false);
// 	}
// }
// /*int check_value_date(std::string token) //ancienne version
// {
//     int i;
//     i = 0;
//     if (token.size() != 10)
//     {
//         return (0);
//     }
//     while (i < 10)
//     {
//         if (token[4] != '-' || token[7] !== '-')
//             return (0);
//         else if (!= isdigit(token[i]))
//             return (0);
//         i++;
//     }
//     while (token[i])
//     {
//         if(check_year(date.substr(0, 4)) == 0)
//             return (0);
//         if(check_mouth(date.substr(5, 2)) == 0)
//             return (0);
//         if(check_day(date.substr(8,2)) == 0)
//             return (0);
//     }
//     return (1);
// }*/
// /*
// int check_value_str(std::string token) //check nbr in str
// {
//     int i = 0;
//     int j = 0;
//     while(token[i])
//     {
//         if (token[i] != '.' && token[i] != ',' && !isdigit(token[i]))
//             return (0);
//         if (token[i] == '.' || token[i] == ',')
//             j++;
//         i++;
//     }
//     if (j > 1)
//         return (0);
//     return (1);
// }
// */
// std::string trim(const std::string &str)
// {
//     if (str.size() == 0)
//         return str;

//     size_t start = 0;
//     size_t end = str.size() - 1;
//     while (std::isspace(str[start]))
//         ++start;
//     while (std::isspace(str[end]))
//         --end;
//     return str.substr(start, end);
// } 

// bool check_file_txt(std::string file_txt)
// {
//     std::ifstream input_txt(file_txt);
//     std::string line;
//     int nbr_line;
//     nbr_line = 0;
//     while (std::getline(input_txt, line))
//     {
//         if(nbr_line == 0)
//         {
//             nbr_line++;
//             continue;
//         }
//         int cmpt_pipe = 0;
//         int cmp_letter = 0;
//         while (line[cmp_letter])
//         {
//             if(line[cmp_letter] == '|') //ok juste un
//                 cmpt_pipe++;
//             cmp_letter++;
//         }
//         if(cmpt_pipe != 1)
//         {
//             std::cerr <<"Error: bad input (bad format)=> " <<std::endl;
//             continue;
//         }
//         std::string delimiteur = "|";
//         size_t pos = 0;
//         std::string token;
//         // line == "2011-01-03 | 1"
//         if ((pos = line.find(delimiteur)) != std::string::npos) 
//         {
//             token = trim(line.substr(0, pos));
//             // token == "2011-01-03"
//             if (token.size()!=0)
//             {
//                 std::cout << token << std::endl; //just test value of date
//             }
//             line.erase(0, pos + delimiteur.length());
//             // line == " 1"
//         }
//         if(token.empty()) //  "     | " 
//         {
// 			std::cerr << "Error: bad input => " << line << std::endl;
// 			continue;
//         }
// 		size_t pos = 0;
//         std::string date = token;
//         try
//         {
//             float value std::stof(trim(line));
//             if (value < 1000)
//             {
//                 std::cerr << "Error: bad input => " << e.what() << line << std::endl;
//                 return false;
//             }
//         }
//         catch (std::invalid_argument &e) {
//             std::cerr << "Error: bad input => " << e.what() << line << std::endl;
//             return false;
//         }
// 		check_value_date(date); //verifie date 
//         //float nbr = std::stof(token);
//         //std::cout << nbr << std::endl;
        
//     }
//     std::cout << "line input :" << line << std::endl; //ignore premiere ligne
//     return true;
// }

/* stof fait maison
float string_to_float(std::string value_str)
{
    float number;
    std::istringstream ss(value_str);
    ss >> number;
    return number;
}
*/

void check_value(float value)
{
    if (value < 0)
        throw std::invalid_argument("not a positive number.");
    if (value > 1000)
        throw std::invalid_argument("too large a number.");
        // return (2);
    // return (1);
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
    std::ifstream file_csv(data_csv.c_str());//verifier 
    if(file_csv.fail())
        throw std::invalid_argument("echec open file : " + data_csv);
    std::string line;
    std::map<Date, float, std::greater<Date> > values;
    std::getline(file_csv, line); //ignore la premiere ligne
    while (std::getline(file_csv, line))
    {
        size_t virgule = line.find_first_of(delimiter);
        Date date = trim(line.substr(0, virgule));
        std::string value_str = trim(line.substr(virgule + 1));
        try 
        {
            //fait maison float value = string_to_float(value_str); //FAUX C++11  stof
            /*float value; fait maison
            sscanf(value_str.c_str(), "%f", "&value");
            a controler
            */
            float value = stof(value_str); //FAUX C++11  stof
            //sscanf(value_str.c_str(), "%f", "&value");
            //std::cout << "VALUE_FLOAT :" << value << std::endl;
            values.insert(std::make_pair(date, value)); //verifie
        }
        catch (const std::invalid_argument &e) {
            throw std::runtime_error(data_csv + " ");
        }
    }
    return values;
}

void read_input(const std::string &filename, char delimiter)
{
    std::map<Date, float, std::greater<Date> > dateValues = parse_csv("data_c.csv", ',');
    std::ifstream file(filename);
    if(file.fail())
        throw std::invalid_argument("echec open file : " + filename);
    std::string line;
    // std::map<Date, float> values;
    std::getline(file, line); //ignore la premiere ligne
    while (std::getline(file, line))
    {
        size_t virgule = line.find_first_of(delimiter);
        try {
            Date date = trim(line.substr(0, virgule));
            if (!date.is_valid())
                throw std::invalid_argument("bad input => " + date.input()); //date invalide 
            std::string value_str = trim(line.substr(virgule + 1));
            //float value = string_to_float(value_str); //FAUX C+11 
            
            float value = stof(value_str);
            check_value(value);
            float result = 0.0;
            //std::cout << "value :" << value << std::endl;
            //value >1000
            //values.insert({date, value});
            result = dateValues.lower_bound(date)->second * value;
            if (dateValues.find(date) == dateValues.end())
            {
                //std::cout << "dateValues[date] :" << dateValues[date] << std::endl;
                //std::cout << "_value :" << value << std::endl;
				result = dateValues.lower_bound(date)->second * value;
            }


            // Afficher en cas ou c'est bon avec "0":
			std::cout << std::setw(2) << std::setfill('0') << date.year();
			std::cout << '-';
			std::cout << std::setw(2) << std::setfill('0') << date.month();
			std::cout << '-';
			std::cout << std::setw(2) << std::setfill('0') << date.day();
            std::cout /*<< date.input()*/ << " => " << value << " = " << result /*value ou result*/<< std::endl;
        }
        catch (const std::invalid_argument &e) {
            std::cout << "Error: " << e.what() << std::endl;
        }
    }
}

#include <algorithm>

int main(int argc, char *argv[])
{
	//argc == 2 ? 
	//text need argument 
	//return 0
    (void) argc;
    try
    {
        //argc == 2
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
    // if (argc == 2)
    // {
    //     BitcoinExchange change;
        
    //     if (!check_file_csv("data.csv"))
    //     {
    //         std::cerr << "Error file : data.csv" << std::endl;
    //     }

    //     std::ifstream input_txt(argv[1]);
    //     //std::getline (input_txt, line);
    //     //std::cout << "line : " << line <<std::endl;
    //     if (input_txt.fail())
    //     {
    //         std::cerr << "Error could don't open FILE "<< argv[1] << std::endl;
    //         return (0);
    //     }
    //     else
    //     {
    //         //verifier erreur input txt
    //         check_file_txt(argv[1]);
    //     }

    //     change.print_value_change(date, value);

	// 	//envoie fichier correcte pour le tester 

    // }

    // else
    //     std::cerr << "besoin du fichier input.txt" << std::endl;
}