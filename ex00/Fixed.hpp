#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed
{
private:
    static const int _fb_value = 8;

private:
    int _value;

public:
    Fixed();

    Fixed(const Fixed& other);

    Fixed& operator=(const Fixed& other);

    ~Fixed();

    int getRawBits() const;

    void setRawBits(int raw);
};

#endif //FIXED_HPP
