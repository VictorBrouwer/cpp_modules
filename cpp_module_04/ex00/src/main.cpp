#include"../include/Animal.hpp"
#include"../include/WrongAnimal.hpp"
#include"../include/Dog.hpp"
#include"../include/Cat.hpp"
#include"../include/WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	// const WrongAnimal* wmeta = new WrongAnimal();
	WrongAnimal* wi = new WrongCat();
	// std::cout << wi->getType() << " " << std::endl;
	wi->makeSound();
	
	return 0;
}