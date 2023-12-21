#include "../include/Array.hpp"

int main()
{
	int *a = new int();
	std::cout << *a << std::endl;
	Array<int> intArray(5);
	std::cout << intArray.size() << std::endl;
	intArray[0] = 1;
	intArray[1] = 2;
	std::cout << intArray[0] << std::endl;
	std::cout << intArray[1] << std::endl;
	std::cout << intArray[2] << std::endl;
	Array<int> intArray2(intArray);
	std::cout << intArray2[0] << std::endl;
	Array<std::string> stringArray(2);
	stringArray[0] = "Hello";
	stringArray[1] = "World";
	std::cout << stringArray[0] << stringArray[1] << std::endl;
	try
	{
		std::cout << stringArray[-2] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}