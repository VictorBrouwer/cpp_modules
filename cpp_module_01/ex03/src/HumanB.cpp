#include"../include/HumanB.hpp"
#include"../include/Weapon.hpp"

HumanB::HumanB(std::string name)
{
	_name = name;
	_weapon = 0;
	std::cout << name << " created" << std::endl;
}

HumanB::~HumanB( void )
{
	std::cout << _name << " destroyed" << std::endl;
}

void	HumanB::setWeapon(Weapon *type)
{
	this->_weapon = type;
}

Weapon*	HumanB::getWeapon() const
{
	return (_weapon);
}

std::string	HumanB::getName() const
{
	return (this->_name);
}

void		HumanB::attack() const
{
	if (_weapon != 0)
		std::cout << this->getName() << " attacks with their weapon " << getWeapon()->getType() << std::endl;
	else
		std::cout << this->getName() << " has no weapon to attack with" << std::endl;
}