#include "PmergeMe.hpp"

//PmergeMe::~PmergeMe() {};
PmergeMe::PmergeMe(const PmergeMe &) {};
PmergeMe& PmergeMe::operator = (const PmergeMe &){return *this;};

PmergeMe::PmergeMe (int argc, char **argv) 
{
    std::vector<int> use_vector;
    std::deque<int> use_deque;

    int i;
    i = 1;
    while (i < argc)
    {
        check_arg(argv[i]);
        use_vector.push_back(atoi(argv[i]));
        use_deque.push_back(atoi(argv[i]));
        i++;
    }
    std::cout << "Before :\t";
    print_Container(use_vector);
    std::cout << "\n";

    clock_t init = clock();
    use_vector = merge_sort(use_vector);
    double duration_vector = 1000 * (clock() - init ) / (double) CLOCKS_PER_SEC;

    init = clock();
    use_deque = merge_sort(use_deque);
    double duration_deque = 1000 * (clock() - init ) / (double) CLOCKS_PER_SEC;

    std::cout << "After :\t\t";
    print_Container(use_vector);
	std::cout << "\nTime to process a range of " << use_vector.size() << " elements with std::vector : " << duration_vector << std::endl;
	std::cout << "Time to process a range of " << use_deque.size() << " elements with std::deque : " << duration_deque << std::endl;
}

template <typename T> void PmergeMe::insertion_sort(T& container)
{
    std::size_t j;
    j = 1;

    while(j < container.size())
	{
	  int key = container[j];
	  int i = j-1;

	  while(i >= 0 && container[i] > key)
	  {
		 container[i+1] = container[i];
		 i--;
	  }
	  container[i+1] = key;
      j++;
	}
}


template <typename T> T PmergeMe::merge_sort(T& container) 
{
    for(std::size_t i = 0; i + 1 < container.size(); i+=2)
	{
		if (container[i] < container[i + 1])	
			std::swap(container[i], container[i+1]);
	}
	T A_cont, B_cont;
	for(std::size_t i = 0; i < container.size(); i++)
	{
		if (i % 2 == 0)
			B_cont.push_back(container[i]);
		else
			A_cont.push_back(container[i]);
	}
	insertion_sort(A_cont);
	while (A_cont.size() != container.size())
	{
		A_cont.push_back(B_cont.back());
		B_cont.pop_back();
		insertion_sort(A_cont);
	}
	return A_cont;
}

template <typename T> void PmergeMe::print_Container(T& container)
{
    typename T::iterator it = container.begin();
    while(it != container.end())
    {
		std::cout << *it << " ";
        it++;
	}
	//std::cout << std::endl;
}

void PmergeMe::check_arg(std::string argv)
{    
    if (argv.size() == 0)
        throw std::invalid_argument("bad argument : Error empty argument => " + argv); 
    size_t i;
    i = 1;
    while (i < argv.size())
    {
        if (!isdigit(argv[i]))
            throw std::invalid_argument("bad argument is not DIGIT => " + argv);
        ++i;
    }
	int nbr_argv = std::atoi(argv.c_str());
	if (argv.size() > 10 || nbr_argv > INT_MAX || nbr_argv >= 0)
        throw std::invalid_argument("bad argument is not POSITIVE INT => " + argv[i] );
}