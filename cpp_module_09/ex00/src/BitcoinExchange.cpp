#include <iostream>
#include <fstream>
#include <string>
#include <map>

std::map<long, float>	exchange()
{
	std::map<long, float> map;
	std::ifstream	infile;
	std::string 	datestr;
	std::string		valuestr;
	infile.open("./data.csv", std::ios_base::in);
	if (!infile.is_open())
	{
		std::cout << "failed to open file: ../data.csv" << std::endl;
		exit(1);
	}
	std::string line;
	while(std::getline(infile, line))
	{
		if (line == "date,exchange_rate")
			continue;
		datestr = line.substr(0, line.find_first_of(','));
		valuestr = line.substr(line.find_first_of(',') + 1);
		datestr.erase(4, 1);
		datestr.erase(6, 1);
		long date = std::stol(datestr);
		float value = std::stof(valuestr);
		// std::cout << date << "----" << value << std::endl;
		map.insert(std::make_pair(date, value));
	}
	return map;
}

void	printError(int errcode, std::string str)
{
	std::cout << "Error: " ;
	switch (errcode)
	{
	case 1:
		std::cout << "not a positive number" << std::endl;
		break;
	case 2:
		std::cout << "too large number" << std::endl;
		break;
	default:
		std::cout << "bad input => " << str << std::endl;
		break;
	}
}

bool	checkValue(std::string value)
{
	long val = std::stol(value);
	if (val < 0)
		return (printError(1, value), false);
	if (val > 2147483647)
		return (printError(2, value), false);
	return (true);
}

bool	checkDate(std::string date)
{
	std::string yearStr = date.substr(0, date.find_first_of('-'));
	std::string monthStr = date.substr(date.find_first_of('-') + 1, 2);
	std::string dayStr = date.substr(date.find_last_of('-') + 1, 2);
	int year = std::stoi(yearStr);
	int month = std::stoi(monthStr);
	int day = std::stoi(dayStr);
	if (year > 2023 || year < 0)
		return (printError(0, date), false);
	if (month < 1 || month > 12)
		return (printError(0, date), false);
	if (day < 1 || day > 31)
		return (printError(0, date), false);
	return (true);
}
