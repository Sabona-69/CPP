#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed{
    private:
        int                fixedNumber;
        static const int    frac;
    public:
        Fixed();
        Fixed(const Fixed& inst);
        ~Fixed();
        Fixed& operator=(const Fixed& inst);
        int getRawBits( void ) const;
        void setRawBits( int const raw ) ;
};

#endif // !FIXED_HPP
