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
        Fixed(const Fixed& inst);
        ~Fixed();
        Fixed& operator=(const Fixed& inst);
        int getRawBite( void ) const;
        void setRawBite( int const raw ) ;
};

#endif // !FIXED_HPP
