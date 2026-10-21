#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
	std::srand(std::time(0));

	try
	{
		std::cout << "=== Shrubbery Test ===" << std::endl;
		Bureaucrat boss("Boss", 1);
		ShrubberyCreationForm shrub("home");

		std::cout << boss << std::endl;
		std::cout << shrub << std::endl;

		boss.signForm(shrub);
		boss.executeForm(shrub);

		std::cout << shrub << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << std::endl;

	try
	{
		std::cout << "=== Robotomy Test ===" << std::endl;
		Bureaucrat boss("Boss", 1);
		RobotomyRequestForm robot("Bender");

		std::cout << boss << std::endl;
		std::cout << robot << std::endl;

		boss.signForm(robot);
		boss.executeForm(robot);
		boss.executeForm(robot);

		std::cout << robot << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << std::endl;

	try
	{
		std::cout << "=== Presidential Pardon Test ===" << std::endl;
		Bureaucrat president("President", 1);
		PresidentialPardonForm pardon("Arthur Dent");

		std::cout << president << std::endl;
		std::cout << pardon << std::endl;

		president.signForm(pardon);
		president.executeForm(pardon);

		std::cout << pardon << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << std::endl;

	try
	{
		std::cout << "=== Fail Test ===" << std::endl;
		Bureaucrat low("Low", 150);
		RobotomyRequestForm failRobot("Target");

		std::cout << low << std::endl;
		std::cout << failRobot << std::endl;

		low.signForm(failRobot);
		low.executeForm(failRobot);
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	return 0;
}
