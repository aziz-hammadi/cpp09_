#ifndef PmergeMe_hpp
#define PmergeMe_hpp

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <climits>

class PmergeMe
{
public:	
	PmergeMe(int argc, char **av);
    void    check_arg(std::string argv);
	template <typename T> void insertion_sort(T& container);
	template <typename T> T merge_sort(T& container);
	template <typename T> void print_Container(T& container);
};

#endif
