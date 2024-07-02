#ifndef FIXED_HPP
#define FIXED_HPP

#include <ostream>

class Fixed
{
private:
    static const int _fractional_bits;
    int              _value;

public:
    Fixed();
    Fixed(int value);
    Fixed(float value);
    Fixed(const Fixed& other);

    ~Fixed();

    Fixed& operator=(const Fixed& other);

    int   toInt() const;
    float toFloat() const;
    int   getRawBits() const;
    void  setRawBits(int raw);
};

std::ostream& operator<<(std::ostream& stream, const Fixed& other);

#endif //FIXED_HPP
