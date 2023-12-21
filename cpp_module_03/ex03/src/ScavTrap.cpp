#include"../include/ScavTrap.hpp"
#include"../include/ClapTrap.hpp"

ScavTrap::ScavTrap()
{
	std::cout << "ScavTrap default constructor called" << std::endl;
	this->setName("no_name");
	this->setHit(ST_HEALTH);
	this->setEnergy(ST_ENERGY);
	this->setDamage(ST_DAMAGE);
}

ScavTrap::ScavTrap(std::string name)
{
	std::cout << "ScavTrap constructor called with name " << name << std::endl;
	this->setName(name);
	this->setHit(ST_HEALTH);
	this->setEnergy(ST_ENERGY);
	this->setDamage(ST_DAMAGE);
}

ScavTrap::ScavTrap(ScavTrap& original_obj) : ClapTrap(original_obj)
{
	std::cout << "ScavTrap copy constructor called on name " << original_obj.getName() << std::endl;
	if (this != &original_obj)
	{
		_name = (original_obj.getName());
		_hitPoints = (original_obj.getHit());
		_energyPoints = (original_obj.getEnergy());
		_attackDamage = (original_obj.getDamage());
	}
}

ScavTrap& ScavTrap::operator=(ScavTrap& other_obj)
{
	std::cout << "ScavTrap assignment operator called on name " << other_obj.getName() << std::endl;
	if (this != &other_obj)
	{
		_name = (other_obj.getName());
		_hitPoints = (other_obj.getHit());
		_energyPoints = (other_obj.getEnergy());
		_attackDamage = (other_obj.getDamage());
	}
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << this->getName() << " ScavTrap destructor called" << std::endl;
}

void	ScavTrap::guardGate()
{
	std::cout << " ScavTrap " << this->getName() << " is now in Gate keeper mode" << std::endl;
}