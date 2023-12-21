#if !defined(WRONG_ANIMAL_H)
#define WRONG_ANIMAL_H

#include<iostream>

class WrongAnimal {
	public:
		WrongAnimal();
		WrongAnimal(std::string name);
		WrongAnimal(WrongAnimal &old_obj);
		WrongAnimal& operator=(const WrongAnimal &other);
		~WrongAnimal();
		void makeSound();
	protected:
		std::string type;
};

#endif // WRONG_ANIMAL_H