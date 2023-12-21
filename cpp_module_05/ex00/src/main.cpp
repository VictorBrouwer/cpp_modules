#include "../include/Bureaucrat.hpp"

// int main()
// {
// 	try
// 	{
// 		Bureaucrat b1("Bert", 12);
// 		b1.incGrade();
// 		Bureaucrat b2("Bob", 2);
// 		b2.incGrade();
// 		b2.incGrade();
// 	}
// 	catch(const Bureaucrat::GradeTooHighException& e)
// 	{
// 		std::cerr << e.what() << '\n';
// 	}
// 	catch(const Bureaucrat::GradeTooLowException& e)
// 	{
// 		std::cerr << e.what() << '\n';
// 	}
// 	catch(const std::exception& e)
// 	{
// 		std::cerr << e.what() << '\n';
// 	}
// }

void testGradeMod(void (Bureaucrat::*func)(), const std::string name,
				  const int age)
{
	try
	{
		Bureaucrat joe(name, age);
		(joe.*func)();
		std::cout << joe ;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}

void tryToCreateInstance(const std::string &name, int grade)
{
	try
	{
		Bureaucrat bureaucrat(name, grade);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}

void testConstructors()
{
	Bureaucrat jack;
	jack.incGrade();
	std::cout << jack;

	Bureaucrat jill(jack);
	jill.incGrade();
	std::cout << jill;
	jack = jill;
	tryToCreateInstance("John", MAX_GRADE / 2);
	tryToCreateInstance("JohnMaxBound", MAX_GRADE - 1);
	tryToCreateInstance("JohnMinBound", MIN_GRADE + 1);
}

int main()
{
	std::cout << "\n--Testing constructors--\n";
	testConstructors();

	std::cout << "\n--Testing GradeModifications--\n";
	testGradeMod(&Bureaucrat::incGrade, "Test Increment", MIN_GRADE / 2);
	testGradeMod(&Bureaucrat::decGrade, "Test Decrement", MIN_GRADE / 2);
	testGradeMod(&Bureaucrat::incGrade, "Test Increment over Max",
				 MAX_GRADE);
	testGradeMod(&Bureaucrat::decGrade, "Test Decrement over Min",
				 MIN_GRADE);

	return (0);
}