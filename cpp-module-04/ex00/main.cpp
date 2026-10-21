#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << j->getType() << std::endl;
    std::cout << i->getType() << std::endl;

    i->makeSound();
    j->makeSound();
    meta->makeSound();

    delete i;
    delete j;
    delete meta;

    
	WrongCat* wrong_cat = new WrongCat();
    WrongAnimal* wrong_a = wrong_cat;

    std::cout << wrong_cat->getType() << std::endl;
	std::cout << wrong_a->getType() << std::endl;

	wrong_cat->makeSound();
    wrong_a->makeSound();

    delete wrong_cat;

    return 0;
}
