#if !defined(AFORM)
#define AFORM

#include <iostream>
#include <stdexcept>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		const std::string	_name;
		bool				_signed;
		const int			_signGrade;
		const int			_execGrade;
	
	public:
		AForm(std::string name, int signGrade, int execGrade);
		AForm();
		AForm(const AForm& rhs);
		AForm &operator=(const AForm& rhs);
		~AForm();
		const std::string&	getName() const { return (this->_name); };
		bool				getSigned() const { return (this->_signed); };
		int					getSignGrade() const { return (this->_signGrade); };
		int					getExecGrade() const { return (this->_execGrade); };
		void				beSigned(const Bureaucrat& bur);
		virtual void		execute(Bureaucrat const & executor) const = 0;
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
		class FormNotSignedException : public std::exception
		{
		public:
			virtual const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream& out, const AForm& Aform);

#endif // AFORM