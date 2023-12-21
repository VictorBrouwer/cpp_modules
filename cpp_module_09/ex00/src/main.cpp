#include"BitcoinExchange.cpp"

int main(int argc, char **argv)
{
	std::map<long, float> map;
	std::ifstream	infile;
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <input_file>" << std::endl;
        return 1;
	}
	map = exchange();
	infile.open(argv[1], std::ios_base::in); // maybe only use ios
	if (!infile.is_open())
	{
		std::cout << "failed to open file: " << argv[1] << std::endl;
		return (1);
	}
	std::string 	line;
	std::string 	datestr;
	std::string		valuestr;
	std::map<long, float>::iterator it;
	while(std::getline(infile, line))
	{
		if (line == "date | value")
			continue;
		datestr = line.substr(0, line.find_first_of('|'));
		if (!checkDate(datestr))
			continue;
		valuestr = line.substr(line.find_first_of('|') + 1);
		if (!checkValue(valuestr))
			continue;
		std::cout << datestr;
		datestr.erase(4, 1);
		datestr.erase(6, 1);
		long date = std::stol(datestr);
		float value = std::stof(valuestr);
		it = map.lower_bound(date);
		if (!map.contains(date) && it != map.begin())
			it--;
		// std::cout << "value  = " << it->second << ", key = " << it->first << std::endl;
		value = value * it->second;
		std::cout <<  " => " << value << std::endl;
	}
}