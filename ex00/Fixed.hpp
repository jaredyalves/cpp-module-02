#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed
{
private:
    static const int _fractional_bits;
    int              _value;

public:
    Fixed();
    Fixed(const Fixed& other);

    ~Fixed();

    Fixed& operator=(const Fixed& other);

    int  getRawBits() const;
    void setRawBits(int raw);
};

#endif //FIXED_HPP
