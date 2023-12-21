#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <stdlib.h>

std::string	FindAndReplace(std::string buffer, std::string s1, std::string s2);

int	main(int argc, char **argv)
{
	std::string	infile_name, s1, s2, buffer, outfile_string;
	const char *outfile_name;
	if (argc != 4)
	{
		std::cout << "wrong number of arguments" << std::endl;
		return (0);
	}
	infile_name = argv[1];
	outfile_name = infile_name.append(".replace").c_str();
	s1 = argv[2];
	s2 = argv[3];
	std::ifstream	infile;
	std::ofstream	outfile;
	infile.open(argv[1], std::ios::in);
	outfile.open(outfile_name, std::ios::out);
	if (!infile.is_open())
	{
		std::cout << "failed to open file: " << argv[1] << std::endl;
		return (1);
	}
	while (std::getline(infile, buffer))
	{
		outfile_string = FindAndReplace(buffer, s1, s2);
		outfile << outfile_string << std::endl;
	}
	infile.close();
	outfile.close();
	return (0);
}

std::string	FindAndReplace(std::string buffer, std::string s1, std::string s2)
{
	std::string	begin, end;
	std::size_t size = s1.length();
	std::size_t found = buffer.find(s1);
	if (found != std::string::npos)
	{
		begin = buffer.substr(0, found);
		end = buffer.substr((found + size), (buffer.length() - found + size));
		begin.append(s2);
		begin.append(end);
	}
	if (found == std::string::npos)
		return (buffer);
	else
	{
		found = begin.find(s1);
		if (found != std::string::npos)
			return (FindAndReplace(begin, s1, s2));
		else
			return (begin);
	}
	return (begin);
}