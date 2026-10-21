#include "Bureaucrat.hpp"

int main()
{
	try
	{
		std::cout << "=== Valid Bureaucrat ===" << std::endl;
		Bureaucrat a("Bob", 2);
		std::cout << a << std::endl;

		std::cout << "\n=== Increment ===" << std::endl;
		a.incrementGrade(); // van 2 → 1
		std::cout << a << std::endl;

		std::cout << "\n=== Increment (should fail) ===" << std::endl;
		a.incrementGrade(); // 1 → 0 → exception
	}
	catch (std::exception& e)
	{
		std::cout << "Caught exception: " << e.what() << std::endl;
	}

	try
	{
		std::cout << "\n=== Invalid constructor ===" << std::endl;
		Bureaucrat b("Tom", 200); // moet throwen
	}
	catch (std::exception& e)
	{
		std::cout << "Caught exception: " << e.what() << std::endl;
	}

	try
	{
		std::cout << "\n=== Decrement test ===" << std::endl;
		Bureaucrat c("Alice", 150);
		std::cout << c << std::endl;

		c.decrementGrade(); // 150 → 151 → exception
	}
	catch (std::exception& e)
	{
		std::cout << "Caught exception: " << e.what() << std::endl;
	}

	return 0;
}
