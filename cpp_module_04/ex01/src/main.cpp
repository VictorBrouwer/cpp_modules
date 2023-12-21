#include"../include/Animal.hpp"
#include"../include/WrongAnimal.hpp"
#include"../include/Dog.hpp"
#include"../include/Cat.hpp"
#include"../include/WrongCat.hpp"
// #include<stdlib.h>

int main()
{
	Animal *animals[6];
	for (int i = 0; i < 6; i++)
	{
		if (i < 3)
			animals[i] = new Cat;
		else
			animals[i] = new Dog;
	}
	for (int i = 0; i < 6; i++)
	{
		std::cout << animals[i]->getType() << " ";
		animals[i]->makeSound();
		delete (animals[i]);
		std::cout << std::endl;
	}
	for (int i = 0; i < 6; i++)
	// system("leak brain");
	return 0;
}