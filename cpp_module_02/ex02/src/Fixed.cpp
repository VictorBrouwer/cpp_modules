#include"../include/Fixed.hpp"

Fixed::Fixed()
{
	// std::cout << "default constructor called" << std::endl;
	_fpnValue = 0;
}

Fixed::Fixed(const int num)
{
	// std::cout << "constructor called with int" << std::endl;
	_fpnValue = (num << _fracBits);
}

Fixed::Fixed(const float num)
{
	// std::cout << "constructor called with float" << std::endl;
	_fpnValue = roundf(num * (1 << _fracBits));
}

Fixed::Fixed(const Fixed &original)
{
	// std::cout << "copy constructor called" << std::endl;
	_fpnValue = original._fpnValue;
}

Fixed::~Fixed()
{
	// std::cout << "Destructor called" << std::endl;
}

// functions

int Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (_fpnValue);
}

void Fixed::setRawBits( int const raw )
{
	(void) raw;
	return ;
}

float Fixed::toFloat( void ) const
{
	float res;

	res = float(_fpnValue) / ((float) (1 << _fracBits));
	return (res);
}

int Fixed::toInt( void ) const
{
	int	res;

	res = _fpnValue >> _fracBits;
	return (res);
}

// operators

std::ostream& operator<<(std::ostream& os, const Fixed& fpn)
{
	os << fpn.toFloat();
	return (os);
}

void	Fixed::operator=(const Fixed& original)
{
	std::cout << "copy assignment operator called" << std::endl;
	_fpnValue = original._fpnValue;
}

Fixed	Fixed::operator+(const Fixed& other) const
{
	Fixed res;

	res._fpnValue = this->_fpnValue + other._fpnValue;
	return (res);
}

Fixed	Fixed::operator-(const Fixed& other) const
{
	Fixed res;

	res._fpnValue = this->_fpnValue - other._fpnValue;
	return (res);
}

Fixed	Fixed::operator*(const Fixed& other) const
{
	float	product;

	product = this->toFloat() * other.toFloat();
	return (Fixed(product));
}

Fixed	Fixed::operator/(const Fixed& other) const
{
	float	quotient;

	quotient = this->toFloat() / other.toFloat();
	return (Fixed(quotient));
}

bool	Fixed::operator<(const Fixed& other) const
{
	return (this->_fpnValue < other._fpnValue);
}

bool	Fixed::operator>(const Fixed& other) const
{
	return (this->_fpnValue < other._fpnValue);

}

bool	Fixed::operator>=(const Fixed& other) const
{
	return (this->_fpnValue >= other._fpnValue);
}

bool	Fixed::operator<=(const Fixed& other) const
{
	return (this->_fpnValue <= other._fpnValue);
}

bool	Fixed::operator==(const Fixed& other) const
{
	return (this->_fpnValue == other._fpnValue);
}

bool	Fixed::operator!=(const Fixed& other) const
{
	return (this->_fpnValue != other._fpnValue);
}

// increment and decremtent

Fixed	Fixed::operator++(void) 
{
	this->_fpnValue += 1;
	return (*this);
}

Fixed	Fixed::operator++(int) 
{
	Fixed ret(*this);

	this->_fpnValue += 1;
	return (ret);
}

Fixed	Fixed::operator--(void) 
{
	this->_fpnValue -= 1;
	return (*this);
}

Fixed	Fixed::operator--(int) 
{
	Fixed ret(*this);

	this->_fpnValue -= 1;
	return (ret);
}

//	min max functions

const Fixed&	Fixed::min(const Fixed& num1, const Fixed& num2)
{
	return ((num1._fpnValue < num2._fpnValue) ? num1 : num2);
}

Fixed&	Fixed::min(Fixed& num1, Fixed& num2)
{
	return ((num1._fpnValue < num2._fpnValue) ? num1 : num2);
}

const Fixed&	Fixed::max(const Fixed& num1, const Fixed& num2)
{
	return ((num1._fpnValue > num2._fpnValue) ? num1 : num2);
}

Fixed&	Fixed::max(Fixed& num1, Fixed& num2)
{
	return ((num1._fpnValue > num2._fpnValue) ? num1 : num2);
}
