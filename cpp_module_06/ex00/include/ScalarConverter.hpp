#if !defined(SCALARCONVERTER_HPP)
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <stdexcept>
#include <limits>
#include <climits>
#include <cfloat>
#include <cmath>

class ScalarConverter
{
public:
	static void convert(std::string str);
private:
	ScalarConverter(/* args */);
	~ScalarConverter();
	enum type_t
	{
		CHAR,
		INT,
		FLOAT,
		DOUBLE,
		PSEUDODOUBLE,
		PSEUDOFLOAT,
		UNKNOWN
	};
	static type_t detectType(std::string str);
	static void printImpossible();
	static void charCase(std::string str);
	static void printPsuedoDouble(std::string str);
	static void printPsuedoFloat(std::string str);
	template <typename T>
	static void printConversions(T type)
	{
		std::cout << "char: ";
		printChar(type);
		std::cout << "int: ";
		printInt(type);
		std::cout << "float: ";
		printFloat(type);
		std::cout << "double: ";
		printDouble(type);
	}
	template <typename T> static void printChar(T c)
	{
		if (std::isnan(c) || CHAR_MIN > c || c > CHAR_MAX)
			std::cout << "impossible" << std::endl;
		else if (std::isprint(static_cast<char>(c)))
			std::cout << "'" << static_cast<char>(c) << "'" << std::endl;
		else
			std::cout << "Non displayable" << std::endl;
	}
	template <typename T> static void printInt(T i)
	{
		if (std::isnan(i) || INT32_MIN > i || i > INT32_MAX)
			std::cout << "impossible" << std::endl;
		else
			std::cout << static_cast<int>(i) << std::endl;
	}
	template <typename T> static void printFloat(T f)
	{
		if (std::isnan(f) || -FLT_MAX > f || f > FLT_MAX)
			std::cout << "impossible" << std::endl;
		else
		{
			std::cout << static_cast<float>(f);
			if (static_cast<float>(f) - static_cast<int>(f) == 0)
				std::cout << ".0";
			std::cout << "f" << std::endl;

		}
	}
	template <typename T> static void printDouble(T d)
	{
		if (std::isnan(d) || -DBL_MAX > d || d > DBL_MAX)
			std::cout << "impossible" << std::endl;
		else
		{
			std::cout << static_cast<double>(d);
			if (static_cast<double>(d) - static_cast<int>(d) == 0)
				std::cout << ".0";
			std::cout << std::endl;
		}
	}
};


#endif // SCALARCONVERTER_HPP
