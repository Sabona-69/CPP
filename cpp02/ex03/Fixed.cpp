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
	this->raw = assign.raw;
	return (*this);
}

Fixed::~Fixed(){
}

float	Fixed::toFloat( void ) const{
	return ((float)this->raw / (1 << frac));
}

int	Fixed::toInt( void ) const{
	return (this->raw / (1 << frac));
}

std::ostream& operator<<(std::ostream& os, const Fixed& assign){
	os << assign.toFloat();
	return os;
}

bool Fixed::operator>(const Fixed& assign) const{
	return (this->toFloat() > assign.toFloat());
}

bool Fixed::operator<(const Fixed& assign) const{
    return this->toFloat() < assign.toFloat();
}

bool Fixed::operator<=(const Fixed& assign) const{
    return this->toFloat() <= assign.toFloat();
}

bool Fixed::operator>=(const Fixed& assign) const{
    return this->toFloat() >= assign.toFloat();
}

bool Fixed::operator==(const Fixed& assign) const{
    return this->toFloat() == assign.toFloat();
}

bool Fixed::operator!=(const Fixed& assign) const{
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

Fixed Fixed::operator*(const Fixed& assign){
	return Fixed(this->toFloat() * assign.toFloat());
}

Fixed Fixed::operator+(const Fixed& assign){
    return Fixed(this->toFloat() + assign.toFloat());
}

Fixed Fixed::operator-(const Fixed& assign){
    return Fixed(this->toFloat() - assign.toFloat());
}


Fixed Fixed::operator/(const Fixed& assign){
    if (assign.toFloat() == 0)
        return *this;
    return Fixed(this->toFloat() / assign.toFloat());
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