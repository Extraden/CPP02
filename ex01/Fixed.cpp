#include <iostream>
#include "Fixed.hpp"

Fixed::Fixed() : _value(0)
{
  std::cout << "Default constructor called\n";
}

Fixed::Fixed(int n)
{
  _value = n << _bits;
  std::cout << "Int constructor called\n";
}

Fixed::Fixed(float f)
{
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
