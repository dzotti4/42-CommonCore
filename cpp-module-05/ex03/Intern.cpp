#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

Intern::Intern(void)
{
}

Intern::Intern(const Intern& other)
{
	(void)other;
}

Intern& Intern::operator=(const Intern& other)
{
	(void)other;
	return *this;
}

Intern::~Intern(void)
{
}

AForm* Intern::makeShrubbery(const std::string& target)
{
	return new ShrubberyCreationForm(target);
}

AForm* Intern::makeRobotomy(const std::string& target)
{
	return new RobotomyRequestForm(target);
}

AForm* Intern::makePardon(const std::string& target)
{
	return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(const std::string& formName, const std::string& target)
{
	std::string names[3] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};

	AForm* (Intern::*forms[3])(const std::string& target) = {
		&Intern::makeShrubbery,
		&Intern::makeRobotomy,
		&Intern::makePardon
	};

	for (int i = 0; i < 3; i++)
	{
		if (formName == names[i])
		{
			std::cout << "Intern creates " << formName << std::endl;
			return (this->*forms[i])(target);
		}
	}
	std::cout << "Intern couldn't create form: " << formName << std::endl;
	return NULL;
}
