
#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	private:
		static const int	frac;
		int					raw;
	public:
		Fixed();
		Fixed(float assign);
		Fixed(int assign);
		Fixed(const Fixed& assign);	
		~Fixed();
		Fixed&	operator=(const Fixed& assign);
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
		float	toFloat( void ) const;
		int		toInt( void ) const;
	};

	std::ostream& operator<<(std::ostream& os, Fixed assign);
#endif