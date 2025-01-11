#include "Fixed.hpp"

Fixed::frac = 8;

Fixed::Fixed(){
    this->fixedNumber = 0;
    std::cout << "Default  constuctor called !" << std::endl;
}

Fixed::~Fixed(){
    std::cout << "Default  destuctor called !" << std::endl;
}

Fixed::Fixed(const Fixed& inst){
    std::cout << "Copy constuctor called !" << std::endl;
}

Fixed::Fixed& operator=(const Fixed& inst){
    std::cout << "Copy assignement operator called !" << std::endl;
    setRawBite(inst.getRawBite());
}

Fixed::int getRawBite() const{
    std::cout << "getRawBite member function called !" << std::endl;
    return fixedNumber;
}

Fixed::void setRawBite(const const raw) {
    std::cout << "setRawBite member function called !" << std::endl;
    fixedNumber = raw;
}

