#include "ScavTrap.hpp"

// constructor
ScavTrap::ScavTrap(void) : ClapTrap("Default")
{
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "ScavTrap default constructor called (" << _name << ")\n";
}

// name constructor
ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name)
{
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "ScavTrap name constructor called (" << _name << ")\n";
}

// copy constructor 
ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
	*this = other;
	std::cout << "ScavTrap copy constructor called (" << _name << ")\n";
}

// copy assignment
ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
	if (this != &other)
		ClapTrap::operator=(other);
	std::cout << "ScavTrap copy assignment operator called (" << _name << ")\n";
	return *this;
}

// destructor
ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap destructor called (" << _name << ")\n";
}

void ScavTrap::attack(const std::string &target)
{
	if (_hitPoints == 0)
	{
		std::cout << "ScavTrap " << _name << " can't attack (no hit points left)\n";
		return ;
	}
	if (_energyPoints == 0)
	{
		std::cout << "ScavTrap " << _name << " can't attack (no energy points left)\n";
		return ;
	}
	_energyPoints--;
	std::cout << "ScavTrap " << _name << " attacks " << target
			  << ", causing " << _attackDamage << " points of damage!\n";
}

void ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap " << _name << " is now in Gate keeper mode.\n";
}
