#include "Fixed.hpp"

#include <cmath>
#include <iostream>

const int Fixed::_fractional_bits = 8;

Fixed::Fixed()
{
    std::cout << "Default constructor called" << std::endl;
    _value = 0;
}

Fixed::Fixed(const int value)
{
    std::cout << "Int constructor called" << std::endl;
    _value = value << _fractional_bits;
}

Fixed::Fixed(const float value)
{
    std::cout << "Float constructor called" << std::endl;
    _value = static_cast<int>(roundf(value * (1 << _fractional_bits)));
}

Fixed::Fixed(const Fixed& other)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        _value = other.getRawBits();
    return *this;
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
