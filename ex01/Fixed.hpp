#ifndef FIXED_HPP
#define FIXED_HPP

#include <ostream>

class Fixed
{
private:
    static const int _fb_value = 8;

private:
    int _value;

public:
    Fixed();

    explicit Fixed(int value);

    explicit Fixed(float value);

    Fixed(const Fixed& other);

    Fixed& operator=(const Fixed& other);

    ~Fixed();

    int getRawBits() const;

    void setRawBits(int raw);

    float toFloat() const;

    int toInt() const;
};

std::ostream& operator<<(std::ostream& stream, const Fixed& other);

#endif //FIXED_HPP
