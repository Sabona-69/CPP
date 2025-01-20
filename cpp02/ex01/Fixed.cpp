#include "Fixed.hpp"

const int Fixed::frac = 8;

Fixed::Fixed(){
    this->fixedNumber = 0;
    std::cout << "Default  constuctor called !" << std::endl;
}

Fixed::~Fixed(){
    std::cout << "Default  destuctor called !" << std::endl;
}

Fixed::Fixed(const int& inst){
    this->setRawBits(inst);
    std::cout << "Copy constuctor called !" << std::endl;
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
    return this->fixedNumber;
}

float Fixed::toFloat( void ) const {
    return ((float)this->fixedNumber / (1 << frac));
}
