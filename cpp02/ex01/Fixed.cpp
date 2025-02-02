#include "Fixed.hpp"

const int Fixed::frac = 8;

Fixed::Fixed(){
    this->fixedNumber = 0;
    std::cout << "Default  constuctor called !" << std::endl;
}

Fixed::~Fixed(){
    std::cout << "Default  destuctor called !" << std::endl;
}

Fixed::Fixed(const float f) {
    fixedNumber = roundf(f * (1 << frac)); 
    std::cout << "Float constructor called" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Fixed& inst){
    os << inst.toFloat();
        return  os;
}

Fixed& Fixed::operator=(const Fixed& inst){
    std::cout << "Copy assignement operator called !" << std::endl;
    this->setRawBits(inst.getRawBits());
    return *this;
}

int Fixed::getRawBits() const{
    std::cout << "getRawBits member function called !" << std::endl;
    return fixedNumber;
}

void    Fixed::setRawBits(const int raw) {
    std::cout << "setRawBits member function called !" << std::endl;
    fixedNumber = raw;
}

int Fixed::toInt( void ) const {
    return this->fixedNumber >> frac ;
}

float Fixed::toFloat(void) const {
	return (float)fixedNumber / (1 << frac);
}