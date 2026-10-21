#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base()
{
}

void identify(Base &p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		return ;
	}
	catch(...)
	{
	}
	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
		return ;
	}
	catch(...)
	{
	}
	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
		return ;
	}
	catch(...)
	{
	}
}

void identify(Base *p)
{
	A *a;
	B *b;
	C *c;

	a = dynamic_cast<A*>(p);
	b = dynamic_cast<B*>(p);
	c = dynamic_cast<C*>(p);

	if (a != NULL)
		std::cout << "A" << std::endl;
	else if (b != NULL)
		std::cout << "B" << std::endl;
	else if (c != NULL)
		std::cout << "C" << std::endl;
}

Base *generate(void)
{
	int random;

	random = std::rand() % 3;
	if (random == 0)
		return (new A);
	else if (random == 1)
		return (new B);
	else
		return (new C);
}
