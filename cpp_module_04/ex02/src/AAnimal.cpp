#include"../include/AAnimal.hpp"

AAnimal::AAnimal() :type("random_AAnimal")
{
	std::cout << "default AAnimal constructor called" << std::endl;
}

AAnimal::AAnimal(std::string type) :type(type)
{
	std::cout << "AAnimal constructor called with type " << this->type << std::endl;
}

AAnimal::AAnimal(AAnimal &old_obj)
{
	std::cout << "AAnimal copy constructor called" << std::endl;
	if (this != &old_obj)
		this->type = old_obj.type;
}

AAnimal& AAnimal::operator=(const AAnimal &other)
{
	if (this != &other)
		this->type = other.type;
	return (*this);
}

const std::string &AAnimal::getType() const
{
	return (this->type);
}

// void	AAnimal::makeSound() const
// {
// 	std::cout << "AAnimal makes sound: " << std::endl;
// }


AAnimal::~AAnimal()
{
	std::cout << "default AAnimal destructor called" << std::endl;
}