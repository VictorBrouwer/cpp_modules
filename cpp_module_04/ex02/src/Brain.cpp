#include"../include/Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain constructor called" << std::endl;
}

Brain::Brain(const Brain &old_obj)
{
	std::cout << "Brain copy constructor called" << std::endl;
	*this = old_obj;
}

Brain& Brain::operator=(const Brain &other)
{
	if (this != &other)
	{
		for (size_t i = 0; i < NUMBER_OF_IDEAS; i++)
		this->ideas[i] = other.ideas[i];
	}
	return (*this);
}

Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}