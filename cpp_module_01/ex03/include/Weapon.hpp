#include <iostream>
#include <string>
#include <iomanip>
#include <stdlib.h>

#ifndef WEAPONCLASS_H
# define WEAPONCLASS_H


class Weapon {
	public:
		Weapon(std::string type);
		~Weapon();
		void				setType(std::string type);
		const std::string&	getType();
	private:
		std::string _type;
};

#endif