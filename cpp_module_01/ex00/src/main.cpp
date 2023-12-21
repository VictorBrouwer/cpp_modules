#include "../include/Zombie.hpp"

int	main ( void )
{
	Zombie *Foo = newZombie("Foo");
	randomChump("Bar");
	delete(Foo);
}