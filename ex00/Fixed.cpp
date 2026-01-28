#include "Fixed.hpp"


Fixed::Fixed() : _value(0) {}
Fixed::Fixed(const Fixed& other)
{
    *this = other;
}

Fixed&	Fixed::operator=(const Fixed& other)
{
  if (this != &other)
  {
    _value = other._value;
  }
  return (*this);
}

Fixed::~Fixed() {}

int Fixed::getRawBits() const
{
  return (_value);
}

void  Fixed::setRawBits(int const raw)
{
  _value = raw;
}
