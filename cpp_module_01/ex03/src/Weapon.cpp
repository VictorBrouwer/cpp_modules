#include"../include/Weapon.hpp"

Weapon::Weapon( std::string type )
{
	_type = type;
	std::cout << "Weapon constructor called" << std::endl;
}

Weapon::~Weapon( void )
{
	 std::cout << "Weapon destructor called" << std::endl;
}

void	Weapon::setType(std::string type)
{
	_type = type;
}

const std::string&	Weapon::getType()
{
	return (_type);
}
