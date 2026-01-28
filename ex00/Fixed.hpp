#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed
{
  public:
    Fixed();
    Fixed(const Fixed& other);
    Fixed&	operator=(const Fixed& other);
    ~Fixed();
    int getRawBits() const;
    void  setRawBits(int const row);

  private:
    int _value;
    static const int  _bits_amount = 8;
};

#endif
