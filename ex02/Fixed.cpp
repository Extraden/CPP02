#include <iostream>
#include <cmath>
#include "Fixed.hpp"

Fixed::Fixed() : _value(0) {}

Fixed::Fixed(const int n)
{
  _value = n << _bits;
}

Fixed::Fixed(const float f)
{
  _value = roundf(f * (1 << _bits));
}

Fixed::Fixed(const Fixed& other)
{
    *this = other;
}

Fixed&	Fixed::operator=(const Fixed& other)
{
  if (this != &other)
  {
    this->_value = other._value;
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

bool	Fixed::operator>(const Fixed& other) const
{
  return(this->_value > other._value);
}

bool	Fixed::operator<(const Fixed& other) const
{
  return(this->_value < other._value);
}

bool	Fixed::operator>=(const Fixed& other) const
{
  return(this->_value >= other._value);
}

bool	Fixed::operator<=(const Fixed& other) const
{
  return(this->_value <= other._value);
}

bool	Fixed::operator==(const Fixed& other) const
{
  return(this->_value == other._value);
}

bool	Fixed::operator!=(const Fixed& other) const
{
  return(this->_value != other._value);
}

Fixed	Fixed::operator+(const Fixed& other) const
{
  return(this->toFloat() + other.toFloat());
}

Fixed	Fixed::operator-(const Fixed& other) const
{
  return(this->toFloat() - other.toFloat());
}

Fixed	Fixed::operator*(const Fixed& other) const
{
  return(this->toFloat() * other.toFloat());
}

Fixed	Fixed::operator/(const Fixed& other) const
{
  return(this->toFloat() / other.toFloat());
}

Fixed&	Fixed::operator++()
{
  this->_value++;
  return (*this);
}

Fixed	Fixed::operator++(int)
{
  Fixed tmp = *this;
  this->_value++;
  return (tmp);
}

Fixed&	Fixed::operator--()
{
  this->_value--;
  return (*this);
}

Fixed	Fixed::operator--(int)
{
  Fixed tmp = *this;
  this->_value--;
  return (tmp);
}

Fixed&  Fixed::min(Fixed& num1, Fixed& num2)
{
  if (num1 < num2)
    return (num1);
  return (num2);
}

const Fixed&  Fixed::min(const Fixed& num1, const Fixed& num2)
{
  if (num1 < num2)
    return (num1);
  return (num2);
}

Fixed&  Fixed::max(Fixed& num1, Fixed& num2)
{
  if (num1 > num2)
    return (num1);
  return (num2);
}

const Fixed&  Fixed::max(const Fixed& num1, const Fixed& num2)
{
  if (num1 > num2)
    return (num1);
  return (num2);
}

