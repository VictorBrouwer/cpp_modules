#include"../include/WrongAnimal.hpp"
#include"../include/WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("cat")
{
	std::cout << "cat constructor called" << std::endl;
}

void WrongCat::makeSound()
{
	std::cout << "miauwww!" << std::endl;
}