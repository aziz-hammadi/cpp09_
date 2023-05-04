#include "PmergeMe.hpp"

int main (int argc, char **argv)
{
    if (argc < 2)
    {
        std::cout << "ARGUMENT : need positive integer sequence" << std::endl;
        return (1);
    }
    try 
    {
        PmergeMe pmergeme(argc, argv);
    }
    catch (std::exception &e)
    {
            std::cout << "Error: " << e.what() << std::endl;
    }
    return (0);
}