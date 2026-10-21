#include "iter.hpp"

void	printInt(const int &x)
{
	std::cout << x << std::endl;
}

void	addOne(int &x)
{
	x++;
}

void	printString(const std::string &x)
{
	std::cout << x << std::endl;
}

int main(void)
{
	int arr[] = {1, 2, 3, 4};
	const int constArr[] = {10, 20, 30, 40};
	std::string words[] = {"hello", "42", "Belgium"};

	iter(arr, 4, printInt);
	iter(arr, 4, addOne);
	std::cout << std::endl;
	iter(arr, 4, printInt);
	std::cout << std::endl;
	
	iter(constArr, 4, printInt);

	std::cout << std::endl;
	iter(words, 3, printString);

	return (0);
}
