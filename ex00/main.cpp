/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammad <ahammad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 10:52:38 by ahammad           #+#    #+#             */
/*   Updated: 2023/04/28 18:29:50 by ahammad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

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

		if (date.is_valid() == false)
		{
			throw std::runtime_error("date CSV");
		}
		try 
        {
            float value;
            sscanf(value_str.c_str(), "%f", &value);
            values.insert(std::make_pair(date, value));
        }
        catch (const std::invalid_argument &e) {
            throw std::runtime_error(data_csv + " ");
        }
    }
    return values;
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
