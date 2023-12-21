#include "../include/Form.hpp"
#include "../include/Bureaucrat.hpp"
// OCF

Form::Form(std::string name, int signGrade, int execGrade)
: _name(name), _signGrade(signGrade), _execGrade(execGrade)
{
	_signed = false;
	if (signGrade > 150 || execGrade > 150)
		throw(Form::GradeTooLowException());
	if (signGrade < 1 || execGrade < 1)
		throw(Form::GradeTooHighException());
	std::cout << "Form constructor called with arguments" << std::endl;
}

Form::Form()
: _name("std_form"), _signGrade(150), _execGrade(150)
{
	_signed = false;
	std::cout << "Default form constructor called without arguments" << std::endl;
}

Form::Form(const Form& rhs)
: _name(rhs.getName()), _signGrade(rhs.getSignGrade()), _execGrade(rhs.getExecGrade())
{
	_signed = (rhs.getSigned());
	std::cout << "Form copy constructor called" << std::endl;
}

Form &Form::operator=(const Form& rhs)
{
	if (this != &rhs)
	{
		this->_signed = rhs.getSigned();
	}
	std::cout << "Form copy assignment operator called" << std::endl;
	return (*this);
}

Form::~Form()
{
	std::cout << "Form " << getName() << " destructed" << std::endl;
}

// PUBLIC MEM FUNCS

void	Form::beSigned(const Bureaucrat& bur)
{
	if (!this->_signed)
	{
		if (bur.getGrade() <= this->_signGrade)
			_signed = true;
		else
			throw(Form::GradeTooLowException());
	}
	else
		std::cout << "Form is already signed" <<std::endl;
}

const std::string&	Form::getName() const
{
	return (this->_name);
}

bool	Form::getSigned() const
{
	return (this->_signed);
}

int	Form::getSignGrade() const
{
	return (this->_signGrade);
}

int	Form::getExecGrade() const
{
	return (this->_execGrade);
}

// OTHER FUNCS

const char* Form::GradeTooLowException::what() const throw()
{
	return ("Exception thrown! Grade too low!");
}

const char* Form::GradeTooHighException::what() const throw()
{
	return ("Exception thrown! Grade too high!");
}

std::ostream& operator<<(std::ostream& out, const Form& form)
{
	out << "Name : " << form.getName() << std::endl
		<< "Signed : " << form.getSigned() << std::endl
		<< "Sign grade : " << form.getSignGrade() << std::endl
		<< "Execute grade : " << form.getExecGrade() << std::endl;
	return (out);
}