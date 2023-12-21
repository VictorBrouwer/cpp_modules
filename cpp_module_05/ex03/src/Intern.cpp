#include "../include/Intern.hpp"

Intern::Intern()
{
	std::cout << "Intern created" << std::endl;
}

Intern::Intern(const Intern& rhs)
{
	std::cout << "Intern created by copy" << std::endl;
	*this = rhs;
}

Intern& Intern::operator=(const Intern& rhs)
{
	if (this != &rhs)
	{
		(void)rhs;
	}
	return (*this);
}

Intern::~Intern()
{
	std::cout << "Intern destructed" << std::endl;
}

AForm* Intern::makePresidentialPardonForm(const std::string &target)
{
	return (new PresidentialPardonForm(target));
}

AForm* Intern::makeRobotomyRequestForm(const std::string &target)
{
	return (new RobotomyRequestForm(target));
}

AForm* Intern::makeShrubberyCreationForm(const std::string &target)
{
	return (new ShrubberyCreationForm(target));
}

AForm* Intern::makeForm(const std::string &name, const std::string &target)
{
	std::string forms[3] = {"presidential pardon", "robotomy request", "shrubbery creation"};
	AForm *(Intern::*creation[3])(const std::string&) = {&Intern::makePresidentialPardonForm, \
						&Intern::makeRobotomyRequestForm, &Intern::makeShrubberyCreationForm};
	for (int i = 0; i < 3; i++)
	{
		if (name == forms[i])
		{
			std::cout << "Intern creates " << name << std::endl;
			return ((this->*creation[i])(target));
		}
	}
	throw Intern::FormNotFoundException();
}