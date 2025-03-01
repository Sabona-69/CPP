#include "Fixed.hpp"

const int Fixed::frac = 8;

Fixed::Fixed(){
    std::cout << "Default constructor called\n";
	this->raw = 0;
}

Fixed::Fixed(const Fixed& assign){
    std::cout << "Copy constructor called\n";
    this->raw = assign.raw;
}

Fixed::Fixed(int assign){	
	std::cout << "Int constructor called\n";
    this->raw = assign * (1 << frac);
}

Fixed::Fixed(float assign){
	std::cout << "Float constructor called\n";
    this->raw = roundf(assign * (1 << frac));
}

Fixed&	Fixed::operator=(const Fixed& assign){
	std::cout << "Copy assignment operator called\n";
	this->raw = assign.raw;
	return (*this);
}

Fixed::~Fixed(){
	std::cout << "Destructor called\n";
}

float	Fixed::toFloat( void ) const{
	return (roundf(this->raw) / (1 << frac));
}

int	Fixed::toInt( void ) const{
	return (this->raw / (1 << frac));
}

std::ostream& operator<<(std::ostream& os, Fixed assign){
	os << assign.toFloat();
	return os;
}

