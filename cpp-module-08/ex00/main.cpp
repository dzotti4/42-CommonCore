#include <iostream>
#include <vector>
#include <list>
#include "easyfind.hpp"

int main(void)
{
	std::vector<int> v;

	v.push_back(10);
	v.push_back(20);
	v.push_back(30);

	std::list<int> l;

	l.push_back(1);
	l.push_back(2);
	l.push_back(3);

	try
	{
		std::vector<int>::iterator it = easyfind(v, 10);
		std::cout << "Found: " << *it << std::endl;
	}
	catch (const std::exception&)
	{
		std::cerr << "Not found" << std::endl;
	}
	try	
	{
		std::vector<int>::iterator it = easyfind(v, 40);
		std::cout << "Found: " << *it << std::endl;
	}
	catch (const std::exception&)
	{
		std::cerr << "Not found" << std::endl;
	}

	try
	{
		std::list<int>::iterator it = easyfind(l, 2);
		std::cout << "Found: " << *it << std::endl;
	}
	catch (const std::exception&)
	{
		std::cerr << "Not found" << std::endl;
	}
	try
	{
		std::list<int>::iterator it = easyfind(l, 6);
		std::cout << "Found: " << *it << std::endl;
	}
	catch(const std::exception&)
	{
		std::cerr << "Not found" << std::endl;
	}

	return (0);
}
