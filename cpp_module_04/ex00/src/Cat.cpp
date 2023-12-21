#include"../include/Cat.hpp"

Cat::Cat() : Animal("cat")
{
	std::cout << "cat constructor called" << std::endl;
}

Cat::Cat(const Cat& old_obj) : Animal(old_obj.getType())
{
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& other)
{
	if (this != &other)
		this->type = other.type;
	return (*this);
}

void Cat::makeSound() const
{
	std::cout << "miauwww!" << std::endl;
}

Cat::~Cat()
{
	std::cout << "cat destructor called" << std::endl;
}