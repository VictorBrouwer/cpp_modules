#if !defined(CAT_H)
#define CAT_H

#include"Animal.hpp"
#include"Brain.hpp"

class Cat : public Animal
{
	public:
		Cat();
		Cat(Cat &old_obj);
		Cat& operator=(const Cat &other);
		~Cat();
		void makeSound() const;
	private:
		Brain *_brain;
};


#endif // CAT_H
