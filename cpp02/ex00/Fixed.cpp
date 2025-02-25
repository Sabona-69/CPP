#include "Fixed.hpp"

const int Fixed::frac = 8;

Fixed::Fixed(){
    std::cout << "Default constructor called\n";
	this->raw = 0;
}

Fixed::Fixed(Fixed const &assign){
    std::cout << "Copy constructor called\n";
    this->raw = assign.raw;
}

Fixed&	Fixed::operator=(const Fixed& assign){
	std::cout << "Copy assignment operator called\n";
	this->setRawBits(assign.getRawBits());
	return (*this);
}

Fixed::~Fixed(){
	std::cout << "Destructor called\n";
}

int	Fixed::getRawBits( void ) const{
    std::cout << "getRawBits member function called\n";
	return raw;
}

void Fixed:: setRawBits( int const raw ){
    std::cout << "setRawBits member function called\n";
	this->raw = raw;
}
