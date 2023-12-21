#include "../include/ClapTrap.hpp"
#include "../include/ScavTrap.hpp"
#include "../include/FragTrap.hpp"
#include "../include/DiamondTrap.hpp"

int main()
{
	DiamondTrap DT_1("Dirk");
	ScavTrap ST_1("Sam");
	DiamondTrap DT_2(DT_1);
	DiamondTrap DT_3("Dennis");
	DT_2 = DT_3;

	std::cout << "\n";

	DT_1.whoami();
	// DT_1.attack("Sam");
	// ST_1.takeDamage(DT_1.getDamage());

	// DT_1.showInformation();
	// std::cout << "\n";
	// ST_1.showInformation();

	// DT_1.attack("Sam");
	// ST_1.takeDamage(DT_1.getDamage());
	// DT_1.attack("Sam");
	// ST_1.takeDamage(DT_1.getDamage());
	// DT_1.attack("Sam");
	// ST_1.takeDamage(DT_1.getDamage());

	// DT_1.showInformation();
	// std::cout << "\n";
	// ST_1.showInformation();

	// ST_1.guardGate();
	// DT_1.highFivesGuys();

	std::cout << "\n";
}