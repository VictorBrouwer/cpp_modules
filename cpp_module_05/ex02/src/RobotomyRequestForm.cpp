#include "../include/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string const &target)
: AForm("RobotomyRequestForm", 72, 45), _target(target)
{
	std::cout << "Robotomy Request Form created" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm &rhs)
: AForm(rhs.getName(), rhs.getSignGrade(), rhs.getExecGrade()), _target(rhs._target)
{
	*this = rhs;
	std::cout << "Robotomy Request Form created by copy" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& rhs)
{
	if (this != &rhs)
	{
		this->_target = rhs._target;
	}
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "Robotomy Request Form destructed" << std::endl;
}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	AForm::execute(executor);
	std::cout << "Drilling noise: drrrrrrrrrrrrrrr" << std::endl;

	if (rand() % 2 == 0)
		std::cout << this->_target << " has been robotomized successfully" << std::endl;
	else
		std::cout << this->_target << " robotomization failed" << std::endl;
}