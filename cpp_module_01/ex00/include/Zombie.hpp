#include <iostream>
#include <string>
#include <iomanip>
#include <stdlib.h>

#ifndef ZOMBIECLASS_H
# define ZOMBIECLASS_H

class Zombie {
	public:
		Zombie (std::string name);
		~Zombie ( void );
		void announce ( void );
	private:
		std::string	name;
};

// 		PROTOTYPES

Zombie* newZombie( std::string name );
void randomChump( std::string name );

#endif