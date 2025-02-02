#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed{
    private:
        int                fixedNumber;
        static const int    frac;
    public:
        Fixed();
        Fixed(const int& inst);
        ~Fixed();
        Fixed& operator=(const Fixed& inst);
        int getRawBits( void ) const;
        void setRawBits( int const raw ) ;
        float   toFloat( void ) const;
        int     toInt ( void ) const;
        bool    operator>(const Fixed& inst);
        bool    operator<(const Fixed& inst);
        bool    operator>=(const Fixed& inst);
        bool    operator<=(const Fixed& inst);
        bool    operator==(const Fixed& inst);
        bool    operator!=(const Fixed& inst);
        float   operator+(const Fixed& inst);
        float   operator-(const Fixed& inst);
        float   operator*(const Fixed& inst);
        float   operator/(const Fixed& inst);
        Fixed&  Fixed::operator++( int );
        Fixed&  Fixed::operator++( int );
        Fixed&  Fixed::operator--( int );
        Fixed&  Fixed::operator--( int );
        Fixed&  min(Fixed& one, Fixed& two);
        Fixed&  min(const Fixed& one, const Fixed& two);
        Fixed&  max(Fixed& one, Fixed& two);
        Fixed&  max(const Fixed& one, const Fixed& two);
};
std::ostream& operator<<(std::ostream& os, const Fixed& inst);
#endif // !FIXED_HPP
