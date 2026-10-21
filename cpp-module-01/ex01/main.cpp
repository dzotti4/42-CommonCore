#include "Zombie.hpp"

int main(void)
{
	int N = 5;

	Zombie* h = zombieHorde(N, "Horde");
	if (!h)
		return (1);
	for (int i = 0; i < N; i++)
		h[i].announce();
	delete[] h;
	return (0);
}
