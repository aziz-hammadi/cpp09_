#ifndef RPN_HPP
#define RPN_HPP
#include <stack>
#include <iostream>

void    ft_addition(int a, int b, std::stack<int> *pile);
void    ft_reverse(std::stack<int>& pile);
void    insert_at_bottom(std::stack<int>& pile, int x);
void    ft_soustraction(int a, int b, std::stack<int> *pile);
void    ft_multiplication(int a, int b, std::stack<int> *pile);
void    ft_division(int a, int b, std::stack<int> *pile);
#endif