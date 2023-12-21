#if !defined(BRAIN_H)
#define BRAIN_H

#define NUMBER_OF_IDEAS 100

#include<iostream>

class Brain
{
	public:
		Brain();
		Brain(const Brain &old_obj);
		Brain& operator=(const Brain &other);
		~Brain();

	protected:
		std::string ideas[100];
};


#endif // BRAIN_H
