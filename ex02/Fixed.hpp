#ifndef FIXED_HPP
#define FIXED_HPP

#include <ostream>

class Fixed
{
private:
    static const int _fractional_bits;
    int              _value;

public:
    static Fixed&       min(Fixed& a, Fixed& b);
    static Fixed&       max(Fixed& a, Fixed& b);
    static const Fixed& min(const Fixed& a, const Fixed& b);
    static const Fixed& max(const Fixed& a, const Fixed& b);

    Fixed();
    Fixed(int value);
    Fixed(float value);
    Fixed(const Fixed& other);

    ~Fixed();

    Fixed& operator=(const Fixed& other);

    bool operator<(const Fixed& other) const;
    bool operator>(const Fixed& other) const;
    bool operator<=(const Fixed& other) const;
    bool operator>=(const Fixed& other) const;
    bool operator==(const Fixed& other) const;
    bool operator!=(const Fixed& other) const;

    Fixed operator+(const Fixed& other) const;
    Fixed operator-(const Fixed& other) const;
    Fixed operator*(const Fixed& other) const;
    Fixed operator/(const Fixed& other) const;

    Fixed& operator++();
    Fixed& operator--();
    Fixed  operator++(int);
    Fixed  operator--(int);

    int   toInt() const;
    float toFloat() const;
    int   getRawBits() const;
    void  setRawBits(int raw);
};

std::ostream& operator<<(std::ostream& stream, const Fixed& other);

#endif //FIXED_HPP
