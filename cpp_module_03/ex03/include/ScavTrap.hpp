#if !defined(SCAVTRAP_H)
#define SCAVTRAP_H
#include"ClapTrap.hpp"

#define ST_HEALTH 100
#define ST_ENERGY 50
#define ST_DAMAGE 20

class ScavTrap : virtual public ClapTrap
{
	public:
		ScavTrap();
		ScavTrap(std::string name);
		ScavTrap(ScavTrap& original_obj);
		ScavTrap& operator=(ScavTrap& other_obj);
		~ScavTrap();
		void	guardGate();
};

#endif // SCAVTRAP_H
