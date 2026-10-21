#include "Fixed.hpp"

Fixed::Fixed() : _raw(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed const& other)
{
    std::cout << "Copy constructor called" << std::endl;
	_raw = other.getRawBits();
}

Fixed& Fixed::operator=(Fixed const& other)
{
    std::cout << "Copy assignment operator called" << std::endl;
	 _raw = other.getRawBits();

    return *this;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return _raw;
}

void Fixed::setRawBits(int const raw)
{
    _raw = raw;
}
