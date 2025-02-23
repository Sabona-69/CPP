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
		float	operator*(const Fixed& assign);
		float	operator+(const Fixed& assign);
		float	operator-(const Fixed& assign);
		float	operator/(const Fixed& assign);
		static Fixed&	min(int& one, int& two);
		static Fixed&	min(const int& one,const int& two);
		static Fixed&	max(int& one, int& two);
		static Fixed&	max(const int& one,const int& two);


	};
	std::ostream& operator<<(std::ostream& os, Fixed assign);
#endif