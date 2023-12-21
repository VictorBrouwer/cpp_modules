#include"../include/FragTrap.hpp"
#include"../include/ScavTrap.hpp"
#include"../include/ClapTrap.hpp"
#include"../include/DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("nameless"), ScavTrap("nameless"), FragTrap("nameless")
{
	std::cout << "DiamondTrap default constructor called" << std::endl;
	_name = ("nameless");
	_hitPoints = (FragTrap::getHit());
	_energyPoints = (ScavTrap::getEnergy());
	_attackDamage = (FragTrap::getDamage());
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name + "_clap_name"), FragTrap(name + "_clap_name")
{
	std::cout << "DiamondTrap constructor called with name " << name << std::endl;
	_name = name;
	_hitPoints = (FragTrap::getHit());
	_energyPoints = (ScavTrap::getEnergy());
	_attackDamage = (FragTrap::getDamage());
}

DiamondTrap::DiamondTrap(DiamondTrap& original_obj)
	: ClapTrap(original_obj), ScavTrap(original_obj), FragTrap(original_obj)
{
	std::cout << "DiamondTrap copy constructor called on name " << original_obj.getName() << std::endl;
	if (this != &original_obj)
	{
		_name = (original_obj.getName());
		_hitPoints = (original_obj.getHit());
		_energyPoints = (original_obj.getEnergy());
		_attackDamage = (original_obj.getDamage());
	}
}

DiamondTrap& DiamondTrap::operator=(DiamondTrap& other_obj)
{
	std::cout << "DiamondTrap assignment operator called on name " << other_obj.getName() << std::endl;
	if (this != &other_obj)
	{
		_name = (other_obj.getName());
		_hitPoints = (other_obj.getHit());
		_energyPoints = (other_obj.getEnergy());
		_attackDamage = (other_obj.getDamage());
	}
	return (*this);
}

void	DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

std::string&	DiamondTrap::getName()
{
	return (this->_name);
}

void DiamondTrap::whoami()
{
	std::cout << "I am DiamondTrap: " << _name << " and I am ClapTrap: " << ClapTrap::getName() << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap destructor called" << std::endl;
}