#include "../include/AForm.hpp"
#include "../include/Bureaucrat.hpp"
// OCF

AForm::AForm(std::string name, int signGrade, int execGrade)
: _name(name), _signGrade(signGrade), _execGrade(execGrade)
{
	_signed = false;
	if (signGrade > 150 || execGrade > 150)
		throw(AForm::GradeTooLowException());
	if (signGrade < 1 || execGrade < 1)
		throw(AForm::GradeTooHighException());
	std::cout << "AForm constructor called with arguments" << std::endl;
}

AForm::AForm()
: _name("std_form"), _signGrade(150), _execGrade(150)
{
	_signed = false;
	std::cout << "Default AForm constructor called without arguments" << std::endl;
}

AForm::AForm(const AForm& rhs)
: _name(rhs.getName()), _signGrade(rhs.getSignGrade()), _execGrade(rhs.getExecGrade())
{
	_signed = (rhs.getSigned());
	std::cout << "AForm copy constructor called" << std::endl;
}

AForm &AForm::operator=(const AForm& rhs)
{
	if (this != &rhs)
	{
		this->_signed = rhs.getSigned();
	}
	std::cout << "AForm copy assignment operator called" << std::endl;
	return (*this);
}

AForm::~AForm()
{
	std::cout << "AForm " << getName() << " destructed" << std::endl;
}

// PUBLIC MEM FUNCS

void	AForm::beSigned(const Bureaucrat& bur)
{
	if (bur.getGrade() <= this->_signGrade)
	{
		_signed = true;
		std::cout << this->getName() << " signed by " << bur.getName() << std::endl;
	}
	else
		throw(AForm::GradeTooLowException());
}

void	AForm::execute(Bureaucrat const & executor) const
{
	if (this->getSigned() == false)
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > this->getExecGrade())
		throw AForm::GradeTooLowException();
}

// OTHER FUNCS

const char* AForm::GradeTooLowException::what() const throw()
{
	return ("Exception thrown! Grade too low!");
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return ("Exception thrown! Grade too high!");
}

const char* AForm::FormNotSignedException::what() const throw()
{
	return ("Exception thrown! AForm not signed!");
}

std::ostream& operator<<(std::ostream& out, const AForm& AForm)
{
	out << "Name : " << AForm.getName() << std::endl
		<< "Signed : " << AForm.getSigned() << std::endl
		<< "Sign grade : " << AForm.getSignGrade() << std::endl
		<< "Execute grade : " << AForm.getExecGrade() << std::endl;
	return (out);
}