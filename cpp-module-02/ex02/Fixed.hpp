#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
private:
    int                 _raw;
    static const int    _fracBits = 8;

    // Private helper: maak een Fixed rechtstreeks uit raw (zonder *256)
    Fixed(int raw, bool raw_tag);

public:
    Fixed();
    Fixed(Fixed const& other);
    Fixed& operator=(Fixed const& other);
    ~Fixed();

    Fixed(int const n);
    Fixed(float const f);

    int     getRawBits(void) const;
    void    setRawBits(int const raw);

    float   toFloat(void) const;
    int     toInt(void) const;

    // Comparisons
    bool operator>(Fixed const& other) const;
    bool operator<(Fixed const& other) const;
    bool operator>=(Fixed const& other) const;
    bool operator<=(Fixed const& other) const;
    bool operator==(Fixed const& other) const;
    bool operator!=(Fixed const& other) const;

    // Arithmetic
    Fixed operator+(Fixed const& other) const;
    Fixed operator-(Fixed const& other) const;
    Fixed operator*(Fixed const& other) const;
    Fixed operator/(Fixed const& other) const;

    // Increment / Decrement
    Fixed& operator++();     // ++a  (pre)
    Fixed  operator++(int);  // a++  (post)
    Fixed& operator--();     // --a
    Fixed  operator--(int);  // a--

    // Min / Max
    static Fixed&       min(Fixed& a, Fixed& b);
    static Fixed const& min(Fixed const& a, Fixed const& b);
    static Fixed&       max(Fixed& a, Fixed& b);
    static Fixed const& max(Fixed const& a, Fixed const& b);
};

std::ostream& operator<<(std::ostream& os, Fixed const& x);

#endif

