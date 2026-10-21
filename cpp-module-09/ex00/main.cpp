#include "BitcoinExchange.hpp"
#include <iostream>
#include <stdexcept>

int	main(int argc, char **argv)
{
	try
	{
		if (argc != 2)
			throw std::runtime_error("Error: could not open file.");

		BitcoinExchange	btc;

		btc.loadDatabase();
		btc.processInputFile(argv[1]);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		return (1);
	}
	return (0);
}
