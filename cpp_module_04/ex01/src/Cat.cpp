#include"../include/Animal.hpp"
#include"../include/Cat.hpp"

Cat::Cat() : Animal("cat")
{
	std::cout << "cat constructor called" << std::endl;
	_brain = new Brain();
}

Cat::Cat(Cat &old_obj) : Animal(old_obj.getType())
{
	std::cout << "Cat copy constructor called" << std::endl;
	if (this != &old_obj)
		this->_brain = new Brain(*(old_obj._brain));
}

Cat& Cat::operator=(const Cat &other)
{
	std::cout << "Cat assignment operator called" << std::endl;
	if (this != &other)
	{
		this->type = other.type;
		delete this->_brain;
		this->_brain = new Brain(*(other._brain));
	}
	return (*this);
}

Cat::~Cat()
{
	std::cout << "cat destructor called" << std::endl;
	delete (_brain);
}

void Cat::makeSound() const
{
	std::cout << "miauwww!" << std::endl;
}