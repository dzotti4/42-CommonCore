#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap a("Alpha");

	a.attack("dummy");
	a.takeDamage(3);
	a.beRepaired(2);

	for (int i = 0; i < 8; i++)
		a.attack("dummy");

	a.attack("dummy");
	a.beRepaired(5);

	a.takeDamage(100);
	a.attack("dummy");
	a.beRepaired(5);

	return 0;
}
