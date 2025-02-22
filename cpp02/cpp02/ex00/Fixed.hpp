#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
	private:
		static const int	frac;
		int					raw;
	public:
		Fixed();
		Fixed(const Fixed& assign);	
		Fixed(const float& assign);
		Fixed(const int& assign);
		~Fixed();
		Fixed&	operator=(Fixed& assign);
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
		float	toFLoat( void ) const;
		int		toInt( void ) const;

	};

#endif