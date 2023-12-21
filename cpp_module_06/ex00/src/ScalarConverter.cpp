#include "../include/ScalarConverter.hpp"


static bool onlyDigits(std::string str)
{
	for (size_t i = 0; i < str.length(); i++)
	{
		if (!std::isdigit(str[i]))
			return false;
	}
	return true;
}

ScalarConverter::type_t	ScalarConverter::detectType(std::string str)
{
	std::string input = str;

	if (input == "nan" || input == "inf" || input == "+inf" || input == "-inf")
		return (PSEUDODOUBLE);
	if (input == "nanf" || input == "inff" || input == "+inff" || input == "-inff")
		return (PSEUDOFLOAT);
	if (input.length() == 1 && !std::isdigit(input[0]))
		return CHAR;
	if (input[0] == '+' || input[0] == '-')
		input.erase(0, 1);
	if (onlyDigits(input))
		return INT;
	if (input.find('.') == std::string::npos)
		return UNKNOWN;
	if (input.find('.') != input.rfind('.'))
		return UNKNOWN;
	if (onlyDigits(input.substr(0, input.find('.'))) && onlyDigits(input.substr(input.find('.') + 1)))
		return DOUBLE;
	if (onlyDigits(input.substr(0, input.find('.'))) && input[input.length() - 1] == 'f' && \
		onlyDigits(input.substr(input.find('.') + 1, (input.find('f') - input.find('.') - 1))))
		return FLOAT;
	return UNKNOWN;
}

void ScalarConverter::printImpossible()
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: impossible" << std::endl;
	std::cout << "double: impossible" << std::endl;
}

void ScalarConverter::printPsuedoDouble(std::string str)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float:  " << str << "f" << std::endl;
	std::cout << "double: " << str << std::endl;
}

void ScalarConverter::printPsuedoFloat(std::string str)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float:  " << str << std::endl;
	std::cout << "double: " << str.substr(0, str.length() - 1) << std::endl;
}

void	ScalarConverter::convert(std::string str)
{
	type_t type = detectType(str);
	switch (type)
	{
	case PSEUDODOUBLE:
		printPsuedoDouble(str);
		break;
	case PSEUDOFLOAT:
		printPsuedoFloat(str);
		break;
	case CHAR:
		printConversions(static_cast<char>(str[0]));
		break;
	case INT:
		printConversions(std::stoi(str));
		break;
	case FLOAT:
		printConversions(std::stof(str));
		break;
	case DOUBLE:
		printConversions(std::stod(str));
		break;
	default:
		printImpossible();
		break;
	}
}
