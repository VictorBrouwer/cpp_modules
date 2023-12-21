#if !defined(FORM)
#define FORM

#include <iostream>
#include <stdexcept>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:

	const std::string	_name;
	bool				_signed;
	const int			_signGrade;
	const int			_execGrade;
	
	public:
	Form(std::string name, int signGrade, int execGrade);
	Form();
	Form(const Form& rhs);
	Form &operator=(const Form& rhs);
	~Form();
	const std::string&	getName() const;
	bool				getSigned() const;
	int					getSignGrade() const;
	int					getExecGrade() const;
	void				beSigned(const Bureaucrat& bur);
	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char* what() const throw();
	};
	class GradeTooHighException : public std::exception
	{
	public:
		virtual const char* what() const throw();
	};
};

std::ostream& operator<<(std::ostream& out, const Form& form);

#endif // FORM