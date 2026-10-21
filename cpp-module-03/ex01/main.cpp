#include "ScavTrap.hpp"

int main(void)
{
	ScavTrap s("Bob");
	
	s.attack("dummy");
	s.takeDamage(30);
	s.beRepaired(10);
	s.guardGate();
		
	s.takeDamage(200);
	s.attack("X");
	s.beRepaired(1);

	return 0;
}
