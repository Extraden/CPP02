#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed
{
  public:
    Fixed();
    Fixed(const int n);
    Fixed(const float f);
    Fixed(const Fixed& other);
    Fixed&	operator=(const Fixed& other);
    Fixed&	operator<<(const Fixed& other);
    ~Fixed();

    int   getRawBits() const;
    void  setRawBits(int const row);
    float toFloat() const;
    int   toInt() const;

  private:
    int _value;
    static const int  _bits = 8;
};

#endif
