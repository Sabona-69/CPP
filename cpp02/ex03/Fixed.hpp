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
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
		float	toFloat( void ) const;
		int		toInt( void ) const;
		Fixed&	operator=(const Fixed& assign);
		bool	operator>(const Fixed& assign);
		bool	operator<(const Fixed& assign);
		bool	operator>=(const Fixed& assign);
		bool	operator<=(const Fixed& assign);
		bool	operator==(const Fixed& assign);
		bool	operator!=(const Fixed& assign);
		Fixed&	operator++( void );
		Fixed	operator++( int );
		Fixed&	operator--( void );
		Fixed	operator--( int );
		Fixed	operator*(const Fixed& assign);
		Fixed	operator+(const Fixed& assign);
		Fixed	operator-(const Fixed& assign);
		Fixed	operator/(const Fixed& assign);

	};
#endif