#if !defined(CAT_H)
#define CAT_H

#include"Animal.hpp"

class Cat : public Animal
{
	public:
		Cat();
		Cat(const Cat &old_obj);
		Cat& operator=(const Cat &other);
		void makeSound() const;
		~Cat();
};


#endif // CAT_H
