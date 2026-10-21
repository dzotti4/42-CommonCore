#include "FragTrap.hpp"

// constructor
FragTrap::FragTrap(void) : ClapTrap("Default")
{
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "FragTrap default constructor called (" << _name << ")\n";
}

// name constructor
FragTrap::FragTrap(const std::string &name) : ClapTrap(name)
{
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "FragTrap name constructor called (" << _name << ")\n";
}

// copy constructor
FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
	*this = other;
	std::cout << "FragTrap copy constructor called (" << _name << ")\n";
}

// copy assignment
FragTrap &FragTrap::operator=(const FragTrap &other)
{
	if (this != &other)
		ClapTrap::operator=(other);
	std::cout << "FragTrap copy assignment operator called (" << _name << ")\n";
	return *this;
}

// destructor
FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap destructor called (" << _name << ")\n";
}

void	FragTrap::attack(const std::string &target)
{
	if (_hitPoints == 0)
	{
		std::cout << "FragTrap " << _name << " can't attack (no hit points left)\n";
		return ;
	}
	if (_energyPoints == 0)
	{
		std::cout << "FragTrap " << _name << " can't attack (no energy point left)\n";
		return ;
	}
	_energyPoints--;
	std::cout << "FragTrap " << _name << " attacks " << target
			  << ", causing " << _attackDamage << " points of damage!\n";
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << _name << " is giving a high five!\n";
}
