#if !defined(DOG_H)
#define DOG_H

#include"AAnimal.hpp"
#include"Brain.hpp"

class Dog : public AAnimal
{
	public:
		Dog();
		void makeSound() const;
		Dog(Dog &old_obj);
		~Dog();
		Dog& operator=(const Dog &other);
	private:
		Brain *_brain;
};

#endif // DOG_H
