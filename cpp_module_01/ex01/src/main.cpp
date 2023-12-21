#include "../include/Zombie.hpp"

int	main ( void )
{
	Zombie z1("Zomb1");
	Zombie *z2 = new Zombie("Zomb2");
	z1.announce();
	z2->announce();
	delete z2;
	std::cout << "\tHorde is arriving" << std::endl;
	Zombie *horde = zombieHorde(5, "Harl");
	for (size_t i = 0; i < 5; i++)
		horde[i].announce();
	delete[] (horde);
	std::cout << "\tHorde has passed" << std::endl;
}
