#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(void) : _name("default"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150)
{
}

AForm::AForm(const std::string& name, int gradeToSign, int gradeToExecute) : _name(name), _isSigned(false),  _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (_gradeToSign < 1 || _gradeToExecute < 1)
		throw GradeTooHighException();
	if (_gradeToSign > 150 || _gradeToExecute > 150)
		throw GradeTooLowException();
}

AForm::AForm(const AForm& other) : _name(other._name), _isSigned(other._isSigned), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
{
}

AForm& AForm::operator=(const AForm& other)
{
	if (this != &other)
	{
		this->_isSigned = other._isSigned;
	}
	return *this;
}

AForm::~AForm(void)
{
}

std::string AForm::getName() const
{
	return _name;
}

bool AForm::getIsSigned() const
{
	return _isSigned;
}

int AForm::getGradeToSign() const
{
	return _gradeToSign;
}

int AForm::getGradeToExecute() const
{
	return _gradeToExecute;
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return "Grade too high";
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return "Grade too low";
}

void AForm::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > _gradeToSign)
		throw GradeTooLowException();
	_isSigned = true;
}

const char* AForm::FormNotSignedException::what() const throw()
{
    return "Form is not signed";
}

void AForm::execute(Bureaucrat const & executor) const
{
    if (!_isSigned)
        throw FormNotSignedException();
    if (executor.getGrade() > _gradeToExecute)
        throw GradeTooLowException();
    executeAction();
}

std::ostream& operator<<(std::ostream& out, const AForm& aform)
{
	out << aform.getName() << ", signed: " << aform.getIsSigned() << ", grade to sign: " << aform.getGradeToSign() << ", grade to execute: " << aform.getGradeToExecute();	
	return out;
}
