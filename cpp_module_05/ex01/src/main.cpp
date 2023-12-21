#include "../include/Bureaucrat.hpp"
#include "../include/Form.hpp"

void tryToCreateInstance(const std::string &name, int signGrade, int execGrade)
{
	try
	{
		Form form(name, signGrade, execGrade);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}

void testConstructors()
{
	tryToCreateInstance("Importand_form", MIN_GRADE, MIN_GRADE);
	tryToCreateInstance("Importand_form", MIN_GRADE, MIN_GRADE - 1);
	tryToCreateInstance("Unimportand_form", MAX_GRADE, MAX_GRADE - 1);
	tryToCreateInstance("Unimportand_form", MAX_GRADE + 1, MAX_GRADE);
}

int main()
{
	std::cout << "\n--Testing constructors--\n";
	testConstructors();

	std::cout << "\n--Testing Forms--\n";
	try
	{
		const Bureaucrat joe("joe", 75);
		Form imp("important", 5, 5);
		Form unimp("unimportant", 125, 125);
		joe.signForm(unimp);
		joe.signForm(imp);
		return (0);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}