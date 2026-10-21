#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main()
{
	try
	{
		std::cout << "=== Valid test ===" << std::endl;
		Bureaucrat bob("Bob", 50);
		Form taxForm("Tax Form", 60, 30);

		std::cout << bob << std::endl;
		std::cout << taxForm << std::endl;

		bob.signForm(taxForm);

		std::cout << taxForm << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << std::endl;

	try
	{
		std::cout << "=== Fail signing test ===" << std::endl;
		Bureaucrat tom("Tom", 100);
		Form secretForm("Secret Form", 50, 20);

		std::cout << tom << std::endl;
		std::cout << secretForm << std::endl;

		tom.signForm(secretForm);

		std::cout << secretForm << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << std::endl;

	try
	{
		std::cout << "=== Invalid form test ===" << std::endl;
		Form badForm("Bad Form", 0, 151);
		std::cout << badForm << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	return 0;
}
