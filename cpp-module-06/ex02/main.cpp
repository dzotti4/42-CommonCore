#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <ctime>

int main(void)
{
	std::srand(std::time(NULL));

	Base *p = generate();
	
	std::cout << "Pointer: ";
	identify(p);

	std::cout << "Reference: ";
	identify(*p);

	delete p;
}
