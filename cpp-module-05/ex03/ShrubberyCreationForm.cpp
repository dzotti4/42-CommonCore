#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void)
	: AForm("ShrubberyCreationForm", 145, 137), _target("default")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
	: AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
	: AForm(other), _target(other._target)
{
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		this->_target = other._target;
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
}

void ShrubberyCreationForm::executeAction() const
{
	std::ofstream outFile((_target + "_shrubbery").c_str());

	if (!outFile.is_open())
		return ;
	
	outFile << "   /\\   " << std::endl;
	outFile << "  /  \\  " << std::endl;
	outFile << " /____\\ " << std::endl;
	outFile << "   ||   " << std::endl;
	outFile << "   ||   " << std::endl;
	
	outFile.close();
}
