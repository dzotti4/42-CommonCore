#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm(void)
	: AForm("RobotomyRequestForm", 72, 45), _target("default")
{
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
	: AForm("RobotomyRequestForm", 72, 45), _target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
	: AForm(other), _target(other._target)
{
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		this->_target = other._target;
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
}

void RobotomyRequestForm::executeAction() const
{
	std::cout << "BZZZZZZ... DRRRRRR... VRRRRRR..." << std::endl;
	if (std::rand() % 2 == 0)
		std::cout << _target << " has been robotomized successfully" << std::endl;
	else
		std::cout << "Robotomy failed on " << _target << std::endl;
}
