#include "../include/ClapTrap.hpp"
#include "../include/FragTrap.hpp"
#include "../include/ScavTrap.hpp"

int main()
{
	FragTrap f1("Frans");
	ScavTrap s1("Sam");

	std::cout << "\n";

	f1.attack("Sam");
	s1.takeDamage(f1.getDamage());

	f1.showInformation();
	std::cout << "\n";
	s1.showInformation();

	f1.attack("Sam");
	s1.takeDamage(f1.getDamage());
	f1.attack("Sam");
	s1.takeDamage(f1.getDamage());
	f1.attack("Sam");
	s1.takeDamage(f1.getDamage());

	f1.showInformation();
	s1.showInformation();
	std::cout << "\n";

	s1.guardGate();
	f1.highFivesGuys();

	std::cout << "\n";
}