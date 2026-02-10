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

