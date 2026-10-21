#include "Zombie.hpp"

int main(void)
{
    Zombie* heapZombie;

    std::cout << "=== STACK ZOMBIE ===" << std::endl;
    randomChump("Stacky");

    std::cout << "=== HEAP ZOMBIE ===" << std::endl;
    heapZombie = newZombie("Heapy");
    heapZombie->announce();

    delete heapZombie;

    return (0);
}
