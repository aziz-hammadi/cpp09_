#include "PmergeMe.hpp"




void PmergeMe::check_arg(std::string argv)
{
    if (argv.size() == 0)
        thow std::invalid_argument("bad argument : Error empty argument => " + argv); 
    size_t i;
    i = 0;
    while (i < argv.lenght())
    {
        if (!isdigit(argv[1]))
            throw std::invalid_argument("bad argument is not DIGIT => " + argv);
        ++i;
    }
	int nbr_argv = std::atoi(av.c_str());
	if (nbr_argv.size() > 10 || nbr_argv > INT_MAX)
		throw CustomException("Error");
}