#include"../include/Dog.hpp"

Dog::Dog() : Animal("dog")
{
	std::cout << "dog constructor called" << std::endl;
}

Dog::Dog(const Dog &old_obj): Animal(old_obj.getType())
{
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog &other)
{
	if (this != &other)
		this->type = other.type;
	return (*this);
}

void Dog::makeSound() const
{
	std::cout << "Woef!" << std::endl;
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
}