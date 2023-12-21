#include "../include/AForm.hpp"
#include "../include/PresidentialPardonForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include "../include/Bureaucrat.hpp"
#include "../include/Intern.hpp"

int main(void)
{
	AForm* rrf;

	try
	{
		Bureaucrat jack("jack", 10);
 		Intern someRandomIntern;
		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		jack.executeForm(*rrf);
		delete rrf;
		someRandomIntern.makeForm("Robomtomy Request", "Bender");
		jack.executeForm(*rrf);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;;
	}
}