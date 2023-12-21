#include "../include/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string const &target)
: AForm("PresidentialPardonForm", 25, 5), _target(target)
{
	std::cout << "Presidential Pardon Form created" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm &rhs)
: AForm(rhs.getName(), rhs.getSignGrade(), rhs.getExecGrade()), _target(rhs._target)
{
	*this = rhs;
	std::cout << "Presidential Pardon Form created by copy" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& rhs)
{
	if (this != &rhs)
	{
		this->_target = rhs._target;
	}
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "Presidential Pardon Form destructed" << std::endl;
}

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	AForm::execute(executor);
	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}