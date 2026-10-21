#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
	std::srand(std::time(0));

	Intern someRandomIntern;
	AForm* form1;
	AForm* form2;
	AForm* form3;
	AForm* form4;

	form1 = someRandomIntern.makeForm("robotomy request", "Bender");
	form2 = someRandomIntern.makeForm("shrubbery creation", "home");
	form3 = someRandomIntern.makeForm("presidential pardon", "Arthur Dent");
	form4 = someRandomIntern.makeForm("unknown form", "Nobody");

	Bureaucrat boss("Boss", 1);

	if (form1)
	{
		boss.signForm(*form1);
		boss.executeForm(*form1);
		delete form1;
	}
	if (form2)
	{
		boss.signForm(*form2);
		boss.executeForm(*form2);
		delete form2;
	}
	if (form3)
	{
		boss.signForm(*form3);
		boss.executeForm(*form3);
		delete form3;
	}
	if (form4)
		delete form4;

	return 0;
}
