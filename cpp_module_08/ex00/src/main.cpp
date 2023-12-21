#include "../include/easyfind.hpp"
#include <array>
#include <vector>

int main()
{
	try
	{
		std::array<int, 5> arr = {1, 3, 5, 7, 9};
		std::cout << *easyfind(arr, 7) << std::endl;
		std::cout << *easyfind(arr, 20) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::vector<int> vec = {2,4,6,8};
		std::cout << *easyfind(vec, 8) << std::endl;
		std::cout << *easyfind(vec, 9) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}