#if !defined(DIAMONDTRAP_H)
#define DIAMONDTRAP_H
#include"ClapTrap.hpp"
#include"ScavTrap.hpp"
#include"FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
	public:
		DiamondTrap();
		DiamondTrap(std::string name);
		DiamondTrap(DiamondTrap& original_obj);
		DiamondTrap& operator=(DiamondTrap& other_obj);
		~DiamondTrap();
		void attack(const std::string& target);
		std::string&	getName();
		void whoami();
	private:
		std::string _name;
};

#endif // DIAMONDTRAP_H
