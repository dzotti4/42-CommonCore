#include "FragTrap.hpp"

int main(void)
{
	FragTrap f("Fred");
	
	f.attack("dummy");
	f.takeDamage(40);
	f.beRepaired(10);
	f.highFivesGuys();
	f.takeDamage(200);
	f.attack("X");

	return 0;
}
