#include "PmergeMe.hpp"

int	main(int argc, char **argv)
{
	PmergeMe	sorter;

	try
	{
		sorter.parseInput(argc, argv);
		sorter.run();
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return (1);
	}
	return (0);
}
