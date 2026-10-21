#include "Dog.hpp"

Dog::Dog() : brain(new Brain())
{
	this->type = "Dog";
	std::cout << "[Dog] Default constructor called" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other), brain(new Brain(*other.brain))
{
	std::cout << "[Dog] Copy constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& other)
{
	std::cout << "[Dog] Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		Animal::operator=(other);
		delete this->brain;
		brain = new Brain(*other.brain);
	}
	return *this;
}

Dog::~Dog()
{
	std::cout << "[Dog] Destructor called" << std::endl;
	delete this->brain;
}

void	Dog::makeSound() const
{
	std::cout << "[Dog] Woof Woof!" << std::endl;
}

void	Dog::setIdea(int idx, const std::string& idea)
{
	this->brain->setIdea(idx, idea);
}

std::string Dog::getIdea(int idx) const
{
	return this->brain->getIdea(idx);
}
