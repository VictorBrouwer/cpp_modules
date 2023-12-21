#include"../include/Weapon.hpp"
#include"../include/HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& type) : _weapon(type)
{
	std::cout << name << " of type HumanA created" << std::endl;
	_name = name;
}

HumanA::~HumanA( void )
{
	std::cout << this->_name << " of type HumanA destroyed" << std::endl;
}

std::string	HumanA::getWeaponType() const
{
	return (this->_weapon.getType());
}

void		HumanA::attack()const
{
	std::cout << this->_name << " attacks with their weapon " << this->getWeaponType() << std::endl;
}