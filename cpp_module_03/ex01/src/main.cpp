#include "../include/ClapTrap.hpp"
#include "../include/ScavTrap.hpp"

int main()
{
	ScavTrap s("john");
	ClapTrap c("claptrep");
	s.attack(c.getName());
	c.takeDamage(s.getDamage());
	c.attack(s.getName());
	s.takeDamage(c.getDamage());
	c.showInformation();
	s.showInformation();
}