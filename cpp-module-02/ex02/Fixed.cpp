#include "Fixed.hpp"
#include <cmath> // roundf

// Private raw constructor (geen prints)
Fixed::Fixed(int raw, bool raw_tag) : _raw(raw)
{
    (void)raw_tag;
}

/* ================
   Canonical form 
   ================ */

Fixed::Fixed() : _raw(0)
{
}

Fixed::Fixed(int const n)
{
    const int scale = 1 << _fracBits; // 256
    _raw = n * scale;
}

Fixed::Fixed(float const f)
{
    const int scale = 1 << _fracBits;
    float scaled = f * scale;
    _raw = (int)roundf(scaled);
}

Fixed::Fixed(Fixed const& other) : _raw(other._raw)
{
}

Fixed& Fixed::operator=(Fixed const& other)
{
    if (this != &other)
        _raw = other._raw;
    return *this;
}

Fixed::~Fixed()
{
}

/* =======================
   Raw access
   ======================= */

int Fixed::getRawBits(void) const
{
    return _raw;
}

void Fixed::setRawBits(int const raw)
{
    _raw = raw;
}

/* =======================
   Conversions
   ======================= */

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

/* =======================
   Stream output
   ======================= */

std::ostream& operator<<(std::ostream& os, Fixed const& x)
{
    os << x.toFloat();
    return os;
}

/* =======================
   Comparisons
   ======================= */

bool Fixed::operator>(Fixed const& other) const  { return _raw > other._raw; }
bool Fixed::operator<(Fixed const& other) const  { return _raw < other._raw; }
bool Fixed::operator>=(Fixed const& other) const { return _raw >= other._raw; }
bool Fixed::operator<=(Fixed const& other) const { return _raw <= other._raw; }
bool Fixed::operator==(Fixed const& other) const { return _raw == other._raw; }
bool Fixed::operator!=(Fixed const& other) const { return _raw != other._raw; }

/* =======================
   Arithmetic
   ======================= */

Fixed Fixed::operator+(Fixed const& other) const
{
    return Fixed(_raw + other._raw, true);
}

Fixed Fixed::operator-(Fixed const& other) const
{
    return Fixed(_raw - other._raw, true);
}

Fixed Fixed::operator*(Fixed const& other) const
{
    long long a = (long long)_raw;
    long long b = (long long)other._raw;

    int result_raw = (int)((a * b) >> _fracBits);
    return Fixed(result_raw, true);
}

Fixed Fixed::operator/(Fixed const& other) const
{
    long long a = (long long)_raw;
    long long b = (long long)other._raw;

    int result_raw = (int)((a << _fracBits) / b);
    return Fixed(result_raw, true);
}

/* =======================
   ++ / --
   ======================= */

Fixed& Fixed::operator++()
{
    _raw += 1;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed old(_raw, true);
    _raw += 1;
    return old;
}

Fixed& Fixed::operator--()
{
    _raw -= 1;
    return *this;
}

Fixed Fixed::operator--(int)
{
    Fixed old(_raw, true);
    _raw -= 1;
    return old;
}

/* =======================
   min / max
   ======================= */

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
    if (a._raw < b._raw)
        return a;
    return b;
}

Fixed const& Fixed::min(Fixed const& a, Fixed const& b)
{
    if (a._raw < b._raw)
        return a;
    return b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
    if (a._raw > b._raw)
        return a;
    return b;
}

Fixed const& Fixed::max(Fixed const& a, Fixed const& b)
{
    if (a._raw > b._raw)
        return a;
    return b;
}
