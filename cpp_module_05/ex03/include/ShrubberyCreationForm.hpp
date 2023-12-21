#if !defined(SCF_HPP)
#define SCF_HPP

#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm
{
private:
	std::string _target;
public:
	ShrubberyCreationForm(std::string const &target);
	ShrubberyCreationForm(ShrubberyCreationForm &rhs);
	ShrubberyCreationForm& operator=(const ShrubberyCreationForm& rhs);
	~ShrubberyCreationForm();
	void	execute(Bureaucrat const & executor) const;
	class FileNotOpenException : public std::exception
	{
		virtual const char* what() const throw()
		{
			return ("Unable to open file");
		}
	};
};


#endif // SCF_HPP
