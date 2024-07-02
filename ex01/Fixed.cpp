#include "Fixed.hpp"

#include <iostream>

Fixed::Fixed(): _value(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value)
{
    std::cout << "Int constructor called" << std::endl;
    _value = value << _fb_value;
}

Fixed::Fixed(const float value)
{
    std::cout << "Float constructor called" << std::endl;
    _value = static_cast<int>(value * static_cast<float>(1 << _fb_value) + (value >= 0 ? 0.5f : -0.5f));
}

Fixed::Fixed(const Fixed& other): _value(0)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed& Fixed::operator=(const Fixed& other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this == &other)
        return *this;
    _value = other.getRawBits();
    return *this;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits() const
{
    return _value;
}

void Fixed::setRawBits(const int raw)
{
    _value = raw;
}

float Fixed::toFloat() const
{
    return static_cast<float>(_value) / static_cast<float>(1 << _fb_value);
}

int Fixed::toInt() const
{
    return _value >> _fb_value;
}

std::ostream& operator<<(std::ostream& stream, const Fixed& other)
{
    stream << other.toFloat();
    return stream;
}
