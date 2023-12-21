#if !defined(BUREACRAT)
#define BUREACRAT

#include <iostream>
#include <stdexcept>
#include "Form.hpp"

#define MAX_GRADE 150
#define MIN_GRADE 1

class Form;

class Bureaucrat
{
	private:
		const std::string	_name;
		int				_grade;
	public:
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat &rhs);
		Bureaucrat &operator=(const Bureaucrat &rhs);
		~Bureaucrat();
		const std::string& getName() const;
		int					getGrade() const;
		void				incGrade();
		void				decGrade();
		void				signForm(Form &form) const;
	class GradeTooHighException : public std::exception
	{
	public:
		virtual const char* what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char* what() const throw();
	};
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureaucrat);

#endif // BUREACRAT

