#include"../include/WrongAnimal.hpp"

WrongAnimal::WrongAnimal() :type("random_animal")
{
	std::cout << "default Wronganimal constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) :type(type)
{
	std::cout << "Wronganimal constructor called with type " << this->type << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal &old_obj)
{
	std::cout << "Wrong animal copy constructor called" << std::endl;
	if (this != &old_obj)
		this->type = old_obj.type;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &other)
{
	if (this != &other)
		this->type = other.type;
	return (*this);
}

void	WrongAnimal::makeSound()
{
	std::cout << "Wrong Animal makes sound:" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "default Wrong animal destructor called" << std::endl;
}