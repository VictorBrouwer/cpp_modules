#ifndef HUMAN_A_CLASS_H
# define HUMAN_A_CLASS_H

#include"Weapon.hpp"

class HumanA {
	public:
		HumanA(std::string name, Weapon& type);
		~HumanA( void );
		std::string			GetName() const;
		void				SetType (std::string type);
		std::string			getWeaponType() const;
		void				attack() const;
	private:
		std::string	_name;
		Weapon&		_weapon;
};

#endif