#include"../include/AAnimal.hpp"
#include"../include/WrongAnimal.hpp"
#include"../include/Dog.hpp"
#include"../include/Cat.hpp"
#include"../include/WrongCat.hpp"
// #include<stdlib.h>

int main()
{
	// AAnimal *a = new AAnimal();
	AAnimal *d = new Dog();
	d->makeSound();
	delete d;
	return 0;
}