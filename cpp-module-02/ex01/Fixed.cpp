#include "Fixed.hpp"

Fixed::Fixed() : _raw(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int const n)
{
    std::cout << "Int constructor called" << std::endl;

    const int scale = 1 << _fracBits;
    _raw = n * scale;
}

Fixed::Fixed(float const f)
{
    std::cout << "Float constructor called" << std::endl;

    const int scale = 1 << _fracBits;
    float scaled = f * scale;
    _raw = (int)roundf(scaled);
}

Fixed::Fixed(Fixed const& other)
{
    std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed& Fixed::operator=(Fixed const& other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        _raw = other._raw;
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

float Fixed::toFloat(void) const
{
    const int scale = 1 << _fracBits;
    return (float)_raw / (float)scale;
}

int Fixed::toInt(void) const
{
    const int scale = 1 << _fracBits;
    return _raw / scale;
}

std::ostream& operator<<(std::ostream& os, Fixed const& x)
{
    os << x.toFloat();
    return os;
}
