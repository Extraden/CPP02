#include <iostream>
#include <cmath>
#include "Fixed.hpp"

Fixed::Fixed() : _value(0)
{
  std::cout << "Default constructor called\n";
}

Fixed::Fixed(const int n)
{
  _value = n << _bits;
  std::cout << "Int constructor called\n";
}

Fixed::Fixed(const float f)
{
  _value = roundf(f * (1 << _bits));
  std::cout << "Float constructor called\n";
}

Fixed::Fixed(const Fixed& other)
{
    std::cout << "Copy constructor called\n";
    *this = other;
}

Fixed&	Fixed::operator=(const Fixed& other)
{
  std::cout << "Copy assignment operator called\n";
  if (this != &other)
  {
    this->_value = other._value;
  }
  return (*this);
}

Fixed&	Fixed::operator*(const Fixed& other)
{
  (void) other;
  return (*this);
}

Fixed::~Fixed()
{
  std::cout << "Destructor called\n";
}

int Fixed::getRawBits() const
{
  std::cout << "getRawBits member function called\n";
  return (_value);
}

void  Fixed::setRawBits(int const raw)
{
  _value = raw;
}

float Fixed::toFloat() const
{
  float res = ((float)_value / (1 << _bits));
  return (res);
}

int   Fixed::toInt() const
{
  int res = _value >> _bits;
  return (res);
}

std::ostream& operator<<(std::ostream& output, Fixed const& num)
{
  output << num.toFloat();
  return (output);
}
