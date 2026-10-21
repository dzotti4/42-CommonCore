#include "ClapTrap.hpp"

// Default constructor
ClapTrap::ClapTrap(void)
	: _name("Default"),
	  _hitPoints(10),
	  _energyPoints(10),
	  _attackDamage(0)
{
	std::cout << "ClapTrap default constructor called (" << _name << ")\n";
}

// Name constructor
ClapTrap::ClapTrap(const std::string &name)
	: _name(name),
	  _hitPoints(10),
	  _energyPoints(10),
	  _attackDamage(0)
{
	std::cout << "ClapTrap name constructor called (" << _name << ")\n";
}

// Copy constructor
ClapTrap::ClapTrap(const ClapTrap &other)
{
	*this = other;
	std::cout << "ClapTrap copy constructor called (" << _name << ")\n";
}

// Copy assignment
ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	if (this != &other)
	{
		_name = other._name;
		_hitPoints = other._hitPoints;
		_energyPoints = other._energyPoints;
		_attackDamage = other._attackDamage;
	}
	std::cout << "ClapTrap copy assignment operator called (" << _name << ")\n";
	return *this;
}

// Destructor
ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap destructor called (" << _name << ")\n";
}

void ClapTrap::attack(const std::string &target)
{
	if (_hitPoints == 0)
	{
		std::cout << "ClapTrap " << _name << " can't attack (no hit points left)\n";
		return ;
	}
	if (_energyPoints == 0)
	{
		std::cout << "ClapTrap " << _name << " can't attack (no energy points left)\n";
		return ;
	}
	_energyPoints--;
	std::cout << "ClapTrap " << _name << " attacks " << target
			  << ", causing " << _attackDamage << " points of damage!\n";
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (_hitPoints == 0)
	{
		std::cout << "ClapTrap " << _name << " is already destroyed (0 hit points)\n";
		return ;
	}

	if (amount >= _hitPoints)
		_hitPoints = 0;
	else
		_hitPoints -= amount;

	std::cout << "ClapTrap " << _name << " takes " << amount
			  << " damage, hit points now: " << _hitPoints << "\n";
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_hitPoints == 0)
	{
		std::cout << "ClapTrap " << _name << " can't repair (no hit points left)\n";
		return ;
	}
	if (_energyPoints == 0)
	{
		std::cout << "ClapTrap " << _name << " can't repair (no energy points left)\n";
		return ;
	}
	_energyPoints--;
	_hitPoints += amount;
	std::cout << "ClapTrap " << _name << " repairs itself for " << amount
			  << " hit points, hit points now: " << _hitPoints << "\n";
}
