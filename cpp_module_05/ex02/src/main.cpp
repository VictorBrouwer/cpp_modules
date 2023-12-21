#include "../include/AForm.hpp"
#include "../include/PresidentialPardonForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/ShrubberyCreationForm.hpp"

int main(void)
{
 	Bureaucrat 				jack("Jack", 6);
 	Bureaucrat 				Bob("Bob", 100);
 	Bureaucrat 				Charles("Charles", 149);
	PresidentialPardonForm	president("Victor");
	RobotomyRequestForm 	robot("Beep");
	ShrubberyCreationForm 	tree1("tree_1");
	ShrubberyCreationForm 	tree2("tree_2");
	try
	{
		jack.incGrade();
		std::cout << jack << std::endl;
		jack.executeForm(president);
		jack.executeForm(robot);
		jack.executeForm(robot);
		jack.executeForm(robot);
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		Bob.executeForm(tree1);
		Charles.executeForm(tree2);
		Bob.executeForm(robot);
		Bob.executeForm(president);
		std::cout << Bob << std::endl;
		std::cout << Bob.getGrade() << std::endl;
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
}