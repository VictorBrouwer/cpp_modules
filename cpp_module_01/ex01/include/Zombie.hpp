#include <iostream>
#include <string>
#include <iomanip>
#include <stdlib.h>

#ifndef ZOMBIECLASS_H
# define ZOMBIECLASS_H

class Zombie {
	public:
		Zombie ( void );
		Zombie (std::string name);
		~Zombie ( void );
		void announce ( void );
		void setName (std::string name);
	private:
		std::string	_name;
};

// 		PROTOTYPES

Zombie* zombieHorde(int	N, std::string name );

#endif