#include "../include/info.hpp"
#include <algorithm>

std::string	GetAndCheckInput(std::string message)
{
	std::string str;

	while (1)
	{
		std::cout << message;
		getline(std::cin, str);
		if (!str.empty())
			return (str);
		else
			std::cout << "Field can not be empty" <<std::endl;
	}
}

std::string	CheckLen(std::string input)
{
	if (input.length() > 10)
	{
		input[9] = '.';
		input = input.substr(0, 10);
	}
	return (input);
}