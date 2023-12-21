#include"../include/Weapon.hpp"
#include"../include/HumanA.hpp"
#include"../include/HumanB.hpp"
// #include"Weapon.cpp"
// #include"HumanA.cpp"
// #include"HumanB.cpp"

#include<iostream>
#include<string>

void	test(int &num)
{
	int x  = 10;
	num = x;
}

int main()
{

	{
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	{
		Weapon club = Weapon("crude spiked club");
		HumanB jim("Jim");
		jim.attack();
		jim.setWeapon(&club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}
	return 0;
}