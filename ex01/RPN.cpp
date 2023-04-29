/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammad <ahammad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 15:23:10 by ahammad           #+#    #+#             */
/*   Updated: 2023/03/30 16:13:01 by ahammad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

void insert_at_bottom(std::stack<int>& pile, int x)
{
 
    if (pile.size() == 0) 
    {
        pile.push(x);
    }
    else 
    {
        int a = pile.top();
        pile.pop();
        insert_at_bottom(pile, x);
 
        pile.push(a);
    }
}

void ft_reverse(std::stack<int>& pile)
{
    if (pile.size() > 0) 
    {
        int x = pile.top();
        pile.pop();
        ft_reverse(pile);
 
        insert_at_bottom(pile, x);
    }
    return;
}

void    ft_addition(int a, int b, std::stack<int> *pile)
{
    int c = a + b;
    pile->push(c);
}

void    ft_soustraction(int a, int b, std::stack<int> *pile)
{
    int c = b - a;
    pile->push(c);
}
void    ft_multiplication(int a, int b, std::stack<int> *pile)
{
    int c = b * a;
    pile->push(c);
}
void    ft_division(int a, int b, std::stack<int> *pile)
{
    int c = b / a;
    pile->push(c);
}