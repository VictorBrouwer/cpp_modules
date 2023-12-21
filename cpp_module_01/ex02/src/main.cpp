#include <iostream>
#include <string>
#include <iomanip>
#include <stdlib.h>

int	main(void)
{
	std::string string = "HI THIS IS BRAIN";
	std::string *string_pointer = &string;
	std::string &string_reference = string;

	std::cout << "The memory address of the string variable: " << &string << std::endl;
	std::cout << "The memory address held by string_pointer: " << string_pointer << std::endl;
	std::cout << "The memory address held by stringREF	 : " << &string_reference << std::endl;

	std::cout << "The value of the string variable: " << string << std::endl;
	std::cout << "The value pointed to by stringPTR: " << *string_pointer << std::endl;
	std::cout << "The value pointed to by stringREF: " << string_reference << std::endl;
}