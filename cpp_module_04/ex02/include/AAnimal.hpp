#if !defined(AAnimal_H)
#define AAnimal_H

#include<iostream>

class AAnimal {
	protected:
		AAnimal();
		AAnimal(std::string name);
	public:
		AAnimal(AAnimal &old_obj);
		AAnimal& operator=(const AAnimal &other);
		virtual ~AAnimal();
		const std::string &getType() const;
		virtual void makeSound() const = 0;
	protected:
		std::string type;
};

#endif // AAAnimal_H
