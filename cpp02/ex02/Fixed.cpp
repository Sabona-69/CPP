#include "Fixed.hpp"

const int Fixed::frac = 8;

Fixed::Fixed(){
	this->raw = 0;
}

Fixed::Fixed(const Fixed& assign){
    this->raw = assign.raw;
}

Fixed::Fixed(int assign){	
    this->raw = assign * (1 << frac);
}

Fixed::Fixed(float assign){
    this->raw = roundf(assign * (1 << frac));
}

Fixed&	Fixed::operator=(const Fixed& assign){
	this->setRawBits(assign.getRawBits());
	return (*this);
}

Fixed::~Fixed(){
}

int	Fixed::getRawBits( void ) const{
	return raw;
}

void Fixed:: setRawBits( int const raw ){
	this->raw = raw;
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

bool Fixed::operator>(const Fixed& assign){

	return (this->toFloat() > assign.toFloat());
}

bool Fixed::operator<(const Fixed& assign){
    return this->toFloat() < assign.toFloat();
}

bool Fixed::operator<=(const Fixed& assign){
    return this->toFloat() <= assign.toFloat();
}

bool Fixed::operator>=(const Fixed& assign){
    return this->toFloat() >= assign.toFloat();
}

bool Fixed::operator==(const Fixed& assign){
    return this->toFloat() == assign.toFloat();
}

bool Fixed::operator!=(const Fixed& assign){
    return this->toFloat() != assign.toFloat();
}

Fixed& Fixed::operator++( void ){
    ++this->raw;
    return  *this;
}

Fixed Fixed::operator++( int ){
    Fixed temp = *this;
    ++this->raw;
    return  temp;
}

Fixed& Fixed::operator--( void ){
    --this->raw;
    return  *this;
}

Fixed Fixed::operator--( int ){
    Fixed temp = *this;
    --this->raw;
    return  temp;
}

float Fixed::operator*(const Fixed& assign){
	return this->toFloat() * assign.toFloat();
}

float Fixed::operator+(const Fixed& assign){
    return this->toFloat() + assign.toFloat();
}

float Fixed::operator-(const Fixed& assign){
    return this->toFloat() - assign.toFloat();
}


float Fixed::operator/(const Fixed& assign){
    return this->toFloat() / assign.toFloat();
}

Fixed&   Fixed::min(Fixed& one, Fixed& two){
    if (one.toFloat() < two.toFloat())
        return one;
    return two;
}

const Fixed&   Fixed::min(const Fixed& one,const Fixed& two){
    if (one.toFloat() < two.toFloat())
        return one;
    return two;
}

Fixed&   Fixed::max(Fixed& one, Fixed& two){
    if (one.toFloat() > two.toFloat())
        return one;
    return two;
}

const Fixed&   Fixed::max(const Fixed& one,const Fixed& two){
    if (one.toFloat() > two.toFloat())
        return one;
    return two;
}