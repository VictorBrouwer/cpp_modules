#if !defined(CLAPTRAP_H)
#define CLAPTRAP_H

#define CT_HEALTH 10
#define CT_ENERGY 10
#define CT_DAMAGE 0

#include<iostream>

class ClapTrap {
	public:
	ClapTrap();
	ClapTrap(std::string name);
	ClapTrap(ClapTrap &old_obj);
	ClapTrap& operator=(const ClapTrap &other);
	~ClapTrap();

	void 				attack(const std::string& target);
	void				takeDamage(unsigned int amount);
	void 				beRepaired(unsigned int amount);
	void 				showInformation();
	const std::string	getName() const;
	unsigned int		getHit() const;
	unsigned int		getEnergy() const;
	unsigned int		getDamage() const;
	void				setName(std::string name);
	void				setHit(unsigned int);
	void				setEnergy(unsigned int);
	void				setDamage(unsigned int);
	

	private:
	std::string _name;
	unsigned int	_hitPoints;
	unsigned int	_energyPoints;
	unsigned int	_attackDamage;
};

#endif // CLAPTRAP_H