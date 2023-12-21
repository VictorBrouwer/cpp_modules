#if !defined(INTERN_HPP)
#define INTERN_HPP

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
private:
public:
	Intern();
	Intern(const Intern& rhs);
	Intern& operator=(const Intern& rhs);
	~Intern();
	AForm* makePresidentialPardonForm(const std::string &target);
	AForm* makeRobotomyRequestForm(const std::string &target);
	AForm* makeShrubberyCreationForm(const std::string &target);
	AForm* makeForm(const std::string &name, const std::string &target);
	class FormNotFoundException : public std::exception
	{
		virtual const char* what() const throw()
		{
			return ("Form not found");
		}
	};
};

#endif // INNTERN_HPP
