#include"../include/FragTrap.hpp"
#include"../include/ClapTrap.hpp"

FragTrap::FragTrap()
{
	std::cout << "FragTrap default constructor called" << std::endl;
	this->setName("no_name");
	this->setHit(FT_HEALTH);
	this->setEnergy(FT_ENERGY);
	this->setDamage(FT_DAMAGE);
}

FragTrap::FragTrap(std::string name)
{
	std::cout << "FragTrap constructor called with name " << name << std::endl;
	this->setName(name);
	this->setHit(FT_HEALTH);
	this->setEnergy(FT_ENERGY);
	this->setDamage(FT_DAMAGE);
}

FragTrap::FragTrap(FragTrap& original_obj) : ClapTrap(original_obj)
{
	std::cout << "FragTrap copy constructor called on name " << original_obj.getName() << std::endl;
	if (this != &original_obj)
	{
		_name = (original_obj.getName());
		_hitPoints = (original_obj.getHit());
		_energyPoints = (original_obj.getEnergy());
		_attackDamage = (original_obj.getDamage());
	}
}

FragTrap& FragTrap::operator=(FragTrap& other_obj)
{
	std::cout << "FragTrap assignment operator called on name " << other_obj.getName() << std::endl;
	if (this != &other_obj)
	{
		_name = (other_obj.getName());
		_hitPoints = (other_obj.getHit());
		_energyPoints = (other_obj.getEnergy());
		_attackDamage = (other_obj.getDamage());
	}
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << this->getName() << " FragTrap destructor called" << std::endl;
}

void	FragTrap::highFivesGuys()
{
	std::cout << " FragTrap " << this->getName() << " wants to high five" << std::endl;
}