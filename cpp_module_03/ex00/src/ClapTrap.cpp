#include"../include/ClapTrap.hpp"

ClapTrap::ClapTrap()
: _name("no_name"), _hitPoints(CT_HEALTH), _energyPoints(CT_ENERGY), _attackDamage(CT_DAMAGE)
{
	std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) 
: _name(name), _hitPoints(CT_HEALTH), _energyPoints(CT_ENERGY), _attackDamage(CT_DAMAGE)
{
	std::cout << "ClapTrap constructor called with name " << name << std::endl;
}

ClapTrap::ClapTrap(ClapTrap &old_obj)
{
	std::cout << "ClapTrap copy constructor called with name " << old_obj.getName() << std::endl;
	if (this != &old_obj)
	{
		_name = old_obj.getName();
		_hitPoints = old_obj.getHit();
		_energyPoints = old_obj.getEnergy();
		_attackDamage = old_obj.getDamage();
	}
}

ClapTrap&	ClapTrap::operator=(const ClapTrap &other)
{
	std::cout << "ClapTrap assignment operator called with name " << other.getName() << std::endl;
	if (this != &other)
	{
		_name = other.getName();
		_hitPoints = other.getHit();
		_energyPoints = other.getEnergy();
		_attackDamage = other.getDamage();
	}
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << _name << " ClapTrap destructor called" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	if (_energyPoints > 0 && _hitPoints > 0)
	{
		std::cout << "ClapTrap " << _name << " attacks " << target <<", causing " << _attackDamage << " points of damage!" << std::endl;
		_energyPoints--;
	}
	else
		std::cout << "ClapTrap " << _name << " cannot to attack" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (_energyPoints > 0 && _hitPoints > 0)
	{
		std::cout << "ClapTrap " << _name << " has taken " << amount << " points of damage!" << std::endl;
		_hitPoints -= amount;
	}
	else
		std::cout << "ClapTrap " << _name << " already died" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_energyPoints > 0 && _hitPoints > 0)
	{
		std::cout << "ClapTrap " << _name << " is being repaired with " << amount << " points" << std::endl;
		_hitPoints += amount;
		_energyPoints--;
	}
	else
		std::cout << "ClapTrap " << _name << " cannot be repaired" << std::endl;
}

void ClapTrap::showInformation()
{
	std::cout << "ClapTrap " << getName() << " has health: " << getHit() << ", has energy: " << getEnergy() << " and has damage: " << getDamage() << std::endl;
}

const std::string		ClapTrap::getName() const
{
	return (_name);
}

unsigned int	ClapTrap::getHit() const
{
	return (_hitPoints);
}

unsigned int	ClapTrap::getEnergy() const
{
	return (_energyPoints);
}

unsigned int	ClapTrap::getDamage() const
{
	return (_attackDamage);
}

void	ClapTrap::setName(std::string name)
{
	_name = name;
}

void	ClapTrap::setHit(unsigned int health)
{
	_hitPoints = health;
}
void	ClapTrap::setEnergy(unsigned int energy)
{
	_energyPoints = energy;
}

void	ClapTrap::setDamage(unsigned int damage)
{
	_attackDamage = damage;
}
