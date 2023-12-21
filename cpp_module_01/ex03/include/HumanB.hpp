#ifndef HUMAN_B_CLASS_H
# define HUMAN_B_CLASS_H

#include"Weapon.hpp"

class HumanB{
	public:
		HumanB(std::string name);
		~HumanB( void );
		std::string	getName() const;
		void		setWeapon (Weapon *type);
		Weapon*		getWeapon() const;
		void		setType (std::string type);
		void		attack() const;
		// std::string	GetName ( void );
	private:
		std::string	_name;
		Weapon*		_weapon;
};

#endif