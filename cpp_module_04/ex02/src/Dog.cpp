#include"../include/AAnimal.hpp"
#include"../include/Dog.hpp"

Dog::Dog() :AAnimal("dog")
{
	std::cout << "dog constructor called" << std::endl;
	_brain = new Brain();
}

Dog::Dog(Dog &old_obj) : AAnimal(old_obj.getType())
{
	std::cout << "Dog copy constructor called" << std::endl;
	if (this != &old_obj)
	{
		this->type = old_obj.type;
		this->_brain = new Brain(*(old_obj._brain));
	}
}

Dog& Dog::operator=(const Dog &other)
{
	std::cout << "Dog assignment operator called" << std::endl;
	if (this != &other)
	{
		this->type = other.type;
		delete this->_brain;
		this->_brain = new Brain(*(other._brain));
	}
	return (*this);
}

Dog::~Dog()
{
	std::cout << "dog destructor called" << std::endl;
	delete (_brain);
}

void Dog::makeSound() const
{
	std::cout << "Woef!" << std::endl;
}