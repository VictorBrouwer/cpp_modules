#if !defined(FragTrap_H)
#define FragTrap_H
#include"ClapTrap.hpp"

#define FT_HEALTH 100
#define FT_ENERGY 100
#define FT_DAMAGE 30

class FragTrap : virtual public ClapTrap
{
	public:
		FragTrap();
		FragTrap(std::string name);
		FragTrap(FragTrap& original_obj);
		FragTrap& operator=(FragTrap& other_obj);
		~FragTrap();
		void	highFivesGuys();
};

#endif // FragTrap_H
