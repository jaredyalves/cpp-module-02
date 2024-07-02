#include "Fixed.hpp"

#include <cmath>
#include <ostream>

const int    Fixed::_fractional_bits = 8;
Fixed&       Fixed::min(Fixed& a, Fixed& b) { return a < b ? a : b; }
Fixed&       Fixed::max(Fixed& a, Fixed& b) { return a > b ? a : b; }
const Fixed& Fixed::min(const Fixed& a, const Fixed& b) { return a < b ? a : b; }
const Fixed& Fixed::max(const Fixed& a, const Fixed& b) { return a > b ? a : b; }

Fixed::Fixed()
{
    _value = 0;
}

Fixed::Fixed(const int value)
{
    _value = value << _fractional_bits;
}

Fixed::Fixed(const float value)
{
    _value = static_cast<int>(roundf(value * (1 << _fractional_bits)));
}

Fixed::Fixed(const Fixed& other)
{
    *this = other;
}

Fixed::~Fixed() {}

Fixed& Fixed::operator=(const Fixed& other)
{
    if (this != &other)
        _value = other.getRawBits();
    return *this;
}

bool Fixed::operator<(const Fixed& other) const
{
    return toFloat() < other.toFloat();
}

bool Fixed::operator>(const Fixed& other) const
{
    return toFloat() > other.toFloat();
}

bool Fixed::operator<=(const Fixed& other) const
{
    return toFloat() <= other.toFloat();
}

bool Fixed::operator>=(const Fixed& other) const
{
    return toFloat() >= other.toFloat();
}

bool Fixed::operator==(const Fixed& other) const
{
    return toFloat() == other.toFloat();
}

bool Fixed::operator!=(const Fixed& other) const
{
    return toFloat() != other.toFloat();
}

Fixed Fixed::operator+(const Fixed& other) const
{
    return Fixed(toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed& other) const
{
    return Fixed(toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed& other) const
{
    return Fixed(toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed& other) const
{
    return Fixed(toFloat() / other.toFloat());
}

Fixed& Fixed::operator++()
{
    _value++;
    return *this;
}

Fixed& Fixed::operator--()
{
    _value--;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed other = *this;
    _value++;
    return other;
}

Fixed Fixed::operator--(int)
{
    Fixed other = *this;
    _value--;
    return other;
}

int Fixed::toInt() const
{
    return _value >> _fractional_bits;
}

float Fixed::toFloat() const
{
    return static_cast<float>(_value) / static_cast<float>(1 << _fractional_bits);
}

int Fixed::getRawBits() const
{
    return _value;
}

void Fixed::setRawBits(const int raw)
{
    _value = raw;
}

std::ostream& operator<<(std::ostream& stream, const Fixed& other)
{
    return stream << other.toFloat();
}
