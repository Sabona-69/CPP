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
        Fixed& Fixed::operator++( void );
        Fixed& Fixed::operator++( int );
        Fixed& Fixed::operator--( void );
        Fixed& Fixed::operator--( int );
        float   min(float& one, float& two);
        float   min(const float& one, const float& two);
        float   max(float& one, float& two);
        float   max(const float& one, const float& two);
};
std::ostream& operator<<(std::ostream& os, const Fixed& inst);
#endif // !FIXED_HPP
