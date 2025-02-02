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
        Fixed(const float inst);
        ~Fixed();
        Fixed& operator=(const Fixed& inst);
        int getRawBits( void ) const;
        void setRawBits( int const raw ) ;
        float   toFloat( void ) const;
        int     toInt ( void ) const;

};
std::ostream& operator<<(std::ostream& os, const Fixed& inst);

#endif // !FIXED_HPP
