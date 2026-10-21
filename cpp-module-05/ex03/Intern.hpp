#ifndef INTERN_HPP
# define INTERN_HPP

# include <string>
# include "AForm.hpp"

class Intern
{
	private:
		AForm* makeShrubbery(const std::string& target);
		AForm* makeRobotomy(const std::string& target);
		AForm* makePardon(const std::string& target);

	public:
		Intern(void);
		Intern(const Intern& other);
		Intern& operator=(const Intern& other);
		~Intern(void);

		AForm* makeForm(const std::string& formName, const std::string& target);
};

#endif
