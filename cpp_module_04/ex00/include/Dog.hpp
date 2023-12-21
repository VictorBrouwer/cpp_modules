#if !defined(DOG_H)
#define DOG_H

#include"Animal.hpp"

class Dog : public Animal
{
	public:
		Dog();
		Dog(const Dog &old_obj);
		Dog& operator=(const Dog &other);
		void makeSound() const;
		~Dog();
};

#endif // DOG_H
