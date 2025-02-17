#include "Fixed.hpp"

const int Fixed::frac = 8;

Fixed::Fixed(){
    this->fixedNumber = 0;
    std::cout << "Default  constuctor called !" << std::endl;
}

Fixed::~Fixed(){
    std::cout << "Default  destuctor called !" << std::endl;
}

Fixed::Fixed(const float &f) {
    fixedNumber = roundf(f * (1 << frac)); 
    std::cout << "Float constructor called" << std::endl;
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

std::ostream& operator<<(std::ostream& os, const Fixed& inst){
    os << inst.toFloat();
        return  os;
}

Fixed& Fixed::operator=(const Fixed& inst){
    std::cout << "Copy assignement operator called !" << std::endl;
    this->setRawBits(inst.getRawBits());
    return *this;
}

bool Fixed::operator>(const Fixed& inst){
    return this->toFloat() > inst.toFloat();
}

bool Fixed::operator<(const Fixed& inst){
    return this->toFloat() < inst.toFloat();
}

bool Fixed::operator<=(const Fixed& inst){
    return this->toFloat() <= inst.toFloat();
}

bool Fixed::operator>=(const Fixed& inst){
    return this->toFloat() >= inst.toFloat();
}

bool Fixed::operator==(const Fixed& inst){
    return this->toFloat() == inst.toFloat();
}

bool Fixed::operator!=(const Fixed& inst){
    return this->toFloat() != inst.toFloat();
}

Fixed& Fixed::operator++( void ){
    ++this->fixedNumber;
    return  *this;
}

Fixed Fixed::operator++( int ){
    Fixed temp = *this;
    ++this->fixedNumber;
    return  temp;
}

Fixed& Fixed::operator--( ){
    --this->fixedNumber;
    return  *this;
}

Fixed& Fixed::operator--( ){
    Fixed temp = *this;
    --this->fixedNumber;
    return  temp;
}

float Fixed::operator+(const Fixed& inst){
    return this->toFloat() + inst.toFloat();
}

float Fixed::operator-(const Fixed& inst){
    return this->toFloat() - inst.toFloat();
}

float Fixed::operator*(const Fixed& inst){
    return this->toFloat() * inst.toFloat();
}

float Fixed::operator/(const Fixed& inst){
    return this->toFloat() / inst.toFloat();
}

Fixed&   min(Fixed& one, Fixed& two){
    if (one.toFloat() < two.toFloat())
        return one;
    return two;
}
Fixed&   min(const Fixed one, const Fixed two){
    if (one.toFloat() < two.toFloat())
        return one;
    return two;
}
Fixed&   max(Fixed& one, Fixed& two){
    if (one.toFloat() > two.toFloat())
        return one;
    return two;
}
Fixed&   max(const Fixed& one, const Fixed& two){
    if (one.toFloat() > two.toFloat())
        return one;
    return two;
}


