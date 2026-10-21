#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Array.hpp"

#define MAX_VAL 750

int	main(void)
{
	Array<int>	numbers(MAX_VAL);
	int			*mirror = new int[MAX_VAL];
	int			i;

	std::srand(std::time(NULL));
	i = 0;
	while (i < MAX_VAL)
	{
		const int	value = std::rand();

		numbers[i] = value;
		mirror[i] = value;
		i++;
	}
	{
		Array<int>	tmp = numbers;
		Array<int>	test(tmp);
	}
	i = 0;
	while (i < MAX_VAL)
	{
		if (mirror[i] != numbers[i])
		{
			std::cerr << "didn't save the same value!!" << std::endl;
			delete[] mirror;
			return (1);
		}
		i++;
	}
	try
	{
		numbers[-2] = 0;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		numbers[MAX_VAL] = 0;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	i = 0;
	while (i < MAX_VAL)
	{
		numbers[i] = std::rand();
		i++;
	}
	delete[] mirror;
	return (0);
}
