#include "Cat.hpp"

Cat::Cat() : brain(new Brain())
{
	this->type = "Cat";
	std::cout << "[Cat] Default constructor called" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other), brain(new Brain(*other.brain))
{
	std::cout << "[Cat] Copy constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& other)
{
	std::cout << "[Cat] Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		Animal::operator=(other);
		delete this->brain;
		brain = new Brain(*other.brain);
	}
	return *this;
}

Cat::~Cat()
{
	std::cout << "[Cat] Destructor called" << std::endl;
	delete this->brain;
}

void	Cat::makeSound() const
{
	std::cout << "[Cat] Meooww!" << std::endl;	
}

void	Cat::setIdea(int idx, const std::string& idea)
{
	this->brain->setIdea(idx, idea);
}

std::string Cat::getIdea(int idx) const
{
	return this->brain->getIdea(idx);
}
