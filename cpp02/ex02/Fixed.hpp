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
		float	toFloat( void ) const;
		int		toInt( void ) const;

		bool	operator>(const Fixed& assign) const ;
		bool	operator<(const Fixed& assign) const ;
		bool	operator>=(const Fixed& assign) const ;
		bool	operator<=(const Fixed& assign) const ;
		bool	operator==(const Fixed& assign) const ;
		bool	operator!=(const Fixed& assign) const ;

		Fixed&	operator++( void );
		Fixed	operator++( int );
		Fixed&	operator--( void );
		Fixed	operator--( int );

		Fixed&	operator=(const Fixed& assign);
		Fixed	operator+(const Fixed& assign);
		Fixed	operator*(const Fixed& assign);
		Fixed	operator-(const Fixed& assign);
		Fixed	operator/(const Fixed& assign);
		static 			Fixed&	min(Fixed& one, Fixed& two);
		static const	Fixed&	min(const Fixed& one,const Fixed& two);
		static			Fixed&	max(Fixed& one, Fixed& two);
		static const	Fixed&	max(const Fixed& one,const Fixed& two);


	};
	std::ostream& operator<<(std::ostream& os, const Fixed& assign);
#endif