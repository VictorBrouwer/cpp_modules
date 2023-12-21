#if !defined(ANIMAL_H)
#define ANIMAL_H

#include<iostream>

class Animal {
	public:
		Animal();
		Animal(std::string name);
		Animal(const Animal &old_obj);
		Animal& operator=(const Animal &other);
		~Animal();
		const std::string &getType() const;
		virtual void makeSound() const;
	protected:
		std::string type;
};

#endif // ANIMAL_H
