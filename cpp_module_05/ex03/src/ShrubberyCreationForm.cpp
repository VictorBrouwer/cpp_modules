#include "../include/ShrubberyCreationForm.hpp"
#include <cstring>

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target)
: AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
	std::cout << "Shrubbery Creation Form created" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm &rhs)
: AForm(rhs.getName(), rhs.getSignGrade(), rhs.getExecGrade()), _target(rhs._target)
{
	std::cout << "Shrubbery Creation Form created by copy" << std::endl;
	*this = rhs;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& rhs)
{
	if (this != &rhs)
	{
		this->_target = rhs._target;
	}
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "Shrubbery Creation Form destructed" << std::endl;
}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	AForm::execute(executor);
	std::string filename = this->_target + "_shrubbery";
	std::ofstream outfile(filename.c_str());
	if (!outfile)
		throw ShrubberyCreationForm::FileNotOpenException();
	outfile << "      /\\      " << std::endl;
	outfile << "     /\\*\\     " << std::endl;
	outfile << "    /\\O\\*\\    " << std::endl;
	outfile << "   /*/\\/\\/\\   " << std::endl;
	outfile << "  /\\O\\/\\*\\/\\  " << std::endl;
	outfile << " /\\*\\/\\*\\/\\/\\ " << std::endl;
	outfile << "/\\O\\/\\/*/\\/O/\\" << std::endl;
}