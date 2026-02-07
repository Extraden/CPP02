#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
  public:
    Fixed();
    Fixed(const int n);
    Fixed(const float f);
    Fixed(const Fixed& other);
    Fixed&	operator=(const Fixed& other);
    ~Fixed();

    Fixed&	operator<<(const Fixed& other);
    Fixed	  operator+(const Fixed& other) const;
    Fixed	  operator-(const Fixed& other) const;
    Fixed   operator*(const Fixed& other) const;
    Fixed   operator/(const Fixed& other) const;

    int   getRawBits() const;
    void  setRawBits(int const row);
    float toFloat() const;
    int   toInt() const;
;
  private:
    int _value;
    static const int  _bits = 8;
};

std::ostream& operator<<(std::ostream& output, Fixed const& num);

#endif
