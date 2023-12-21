#include"../include/Animal.hpp"

Animal::Animal() : type("random_animal")
{
	std::cout << "default animal constructor called" << std::endl;
}

Animal::Animal(std::string type) :type(type)
{
	std::cout << "animal constructor called with type " << this->type << std::endl;
}

Animal::Animal(const Animal &old_obj)
{
	std::cout << "animal copy constructor called" << std::endl;
	if (this != &old_obj)
		*this = old_obj;
}

Animal& Animal::operator=(const Animal &other)
{
	if (this != &other)
		this->type = other.type;
	return (*this);
}

const std::string &Animal::getType() const
{
	return (this->type);
}

void	Animal::makeSound() const
{
	std::cout << "Animal makes sound: " << std::endl;
}


Animal::~Animal()
{
	std::cout << "default animal destructor called" << std::endl;
}