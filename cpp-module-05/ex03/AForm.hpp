#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <string>
# include <exception>

class Bureaucrat;

class AForm
{
	private:
		const std::string _name;
		bool _isSigned;
		const int _gradeToSign;
		const int _gradeToExecute;

	public:
		AForm(void);
		AForm(const std::string& name, int gradeToSign, int gradeToExecute);
		AForm(const AForm &other);
		AForm &operator=(const AForm &other);
		virtual ~AForm(void);

		std::string getName() const;
		bool	getIsSigned() const;
		int		getGradeToSign() const;
		int		getGradeToExecute() const;

		void beSigned(const Bureaucrat& bureaucrat);

		class GradeTooHighException : public std::exception
		{
			public:
				const char* what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				const char* what() const throw();
		};


		void execute(Bureaucrat const & executor) const;
		virtual void executeAction() const = 0;
		class FormNotSignedException : public std::exception
		{
			public:
				const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream& out, const AForm& aform);

#endif
