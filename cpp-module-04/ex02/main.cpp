#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	const Animal* j = new Dog();
    const Animal* i = new Cat();

    delete j;
    delete i;



	const int n = 10;
	Animal* animals[n];

	for (int k = 0; k < n; k++)
	{
		if (k < n / 2)
			animals[k] = new Dog();
		else
			animals[k] = new Cat();
	}
	for (int k = 0; k < n; k++)
		delete animals[k];
	



    Dog basic;
    basic.setIdea(0, "bone");
	{
		Dog tmp = basic;
		basic.setIdea(0, "none");
		std::cout << "tmp: " << tmp.getIdea(0) << std::endl;
		std::cout << "basic: " << basic.getIdea(0) << std::endl;
	}
	

	 
	// Animal* A = new Animal();

    return 0;
}

