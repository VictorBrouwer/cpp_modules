#include "../include/Zombie.hpp"

Zombie::Zombie (void)
{
	std::cout << "default Zombie constructor called" << std::endl;
}

Zombie::Zombie (std::string name)
{
	this->_name = name;
	std::cout << this->_name << " created" << std::endl;
}

void	Zombie::announce ( void )
{
	std::cout << this->_name << ":  BraiiiiiiinnnzzzZ..." << std::endl;
}

void 	Zombie::setName (std::string name)
{
	_name = name;
}

Zombie::~Zombie ( void )
{
	std::cout << "default Zombie destructor called" << std::endl;
}