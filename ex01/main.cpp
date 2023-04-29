/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammad <ahammad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 15:22:59 by ahammad           #+#    #+#             */
/*   Updated: 2023/03/30 16:05:50 by ahammad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cerr << "les arguments ne sont pas suffisant\n"<< std::endl;
        std::cerr << "Error";
        return (0);
    }
    else
    {
        std::string s = argv[1];
    }
    std::string s = argv[1];

    int i;
    i = 0;
    std::stack<int> pile; //utilisation de la stack pour stocker les chiffres
    while (s[i])
    {
        if (isdigit(s[i]))
        {
            pile.push(s[i] - '0');
        }
        else
        {
            if (s[i] == '+')
            {
				if (pile.size() >= 2)
                {
                    int a = pile.top();
				    pile.pop();
				    int b = pile.top();
				    pile.pop();
				    ft_addition(a, b, &pile);
                }
                else 
                {
                    std::cout << "Error";
                    return (0);
                }
            }
            else if (s[i] == '-')
            {
				if (pile.size() >= 2)
                {
                    int a = pile.top();
				    pile.pop();
				    int b = pile.top();
				    pile.pop();
				    ft_soustraction(a, b, &pile);
                }
                else 
                {
                    std::cout << "Error";
                    return (0);
                }
            }
            else if (s[i] == '/')
            {
				if (pile.size() >= 2)
                {
                    int a = pile.top();
				    pile.pop();
				    int b = pile.top();
				    pile.pop();
                    if (a == 0)
                    {
                        std::cout << "invalid argument" << std::endl;
                        return (0);
                    }
				    ft_division(a, b, &pile);
                }
                else 
                {
                    std::cout << "Error";
                    return (0);
                }            }
            else if (s[i] == '*')
            {
				if (pile.size() >= 2)
                {
                    int a = pile.top();
				    pile.pop();
				    int b = pile.top();
				    pile.pop();
				    ft_multiplication(a, b, &pile);
                }
                else 
                {
                    std::cout << "Error";
                    return (0);
                }            }
            else if ( s[i] == ' ')
            {
                
            }
            else
            {
                std::cout << "Error\n";
                return (0);
            }
        }
        i++;
    }

    ft_reverse(pile);

    while (!pile.empty())
    {
        std::cout << pile.top() << " ";
        pile.pop();
    }
    std::cout << "\n";
    return (0);
}