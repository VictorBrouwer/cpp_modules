#include "RPN.cpp"

int main(int argc, char **argv)
{
	std::string str;
	if (argc == 2)
	{
		str = argv[1];
		try
		{
			int res = rpn(str);
			std::cout << res << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
			return EXIT_FAILURE;
		}
	}
}
