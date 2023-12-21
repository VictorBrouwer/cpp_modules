#include "../include/ClapTrap.hpp"

int	main()
{
	ClapTrap c1("charlie");
	ClapTrap c2("conrad");
	ClapTrap c3(c1);
	c3 = c2;
	ClapTrap c4;

	c1.attack("conrad");
	c2.takeDamage(0);
	c2.showInformation();
	c2.beRepaired(2);
	c2.showInformation();
	c1.takeDamage(5);
	c1.showInformation();
}