#include "../include/Bureaucrat.hpp"
#include "../include/AForm.hpp"

// OCF

Bureaucrat::Bureaucrat() : _name("stdBureaucrat"), _grade(75)
{
	std::cout << "default bureaucrat created" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name) 
{
	std::cout << "bureaucrat " << name << " created" << std::endl;
	if (grade < 1)
		throw (Bureaucrat::GradeTooHighException());
	else if (grade > 150)
		throw (Bureaucrat::GradeTooLowException());
	_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &rhs)
: _name(rhs._name), _grade(rhs._grade)
{
	std::cout << "bureaucrat copy constructor called" << std::endl;
	if (this != &rhs)
		*this = rhs;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &rhs)
{
	std::cout << "bureaucrat assignment operator called" << std::endl;
	if (this != &rhs)
		this->_grade = rhs.getGrade();
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "default bureaucrat destructor called" << std::endl;
}

// PUBLIC MEM FUNCS

const std::string& Bureaucrat::getName() const
{
	return (this->_name);
}

int Bureaucrat::getGrade() const
{
	return (this->_grade);
}

void	Bureaucrat::incGrade()
{
	if (_grade < 2)
		throw (Bureaucrat::GradeTooHighException());
	_grade--;
	std::cout << "grade incremented to " << getGrade() << std::endl;
}

void	Bureaucrat::decGrade()
{
	if (_grade > 149)
		throw (Bureaucrat::GradeTooLowException());
	_grade++;
	std::cout << "grade decremented to " << getGrade() << std::endl;
}


void	Bureaucrat::signForm(AForm &Aform) const
{
	try
	{
		Aform.beSigned(*this);
		std::cout << this->getName() << " signed " << Aform.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << this->getName() << " couldn't signed " << Aform.getName() << " because " << std::endl;
		std::cerr << e.what() << '\n';
	}
}

void	Bureaucrat::executeForm(AForm & Aform) const
{
	try
	{
		Aform.beSigned(*this);
		Aform.execute(*this);
		std::cout << this->getName() << " executed " << Aform.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << this->getName() << " couldn't execute " << Aform.getName() << " because " << std::endl;
		std::cerr << e.what() << '\n';
	}
}

// OTHER FUNCS

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Exception thrown! Grade too high");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Exception thrown! Grade too low");
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureaucrat)
{
	out << "Name: " << bureaucrat.getName() << std::endl
		<< "Grade: " << bureaucrat.getGrade() << std::endl;
	return (out);
}