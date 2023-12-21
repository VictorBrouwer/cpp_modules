#include"../include/Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "default constructor called" << std::endl;
	_fpnValue = 0;
}

Fixed::Fixed(const int num)
{
	std::cout << "constructor called with int" << std::endl;
	_fpnValue = (num << _fracBits);
}

Fixed::Fixed(const float num)
{
	std::cout << "constructor called with float" << std::endl;
	_fpnValue = roundf(num * (1 << _fracBits));
}

Fixed::Fixed(const Fixed &original)
{
	std::cout << "copy constructor called" << std::endl;
	_fpnValue = original._fpnValue;
}

void	Fixed::operator=(const Fixed& original)
{
	std::cout << "copy assignment operator called" << std::endl;
	_fpnValue = original._fpnValue;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

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

std::ostream& operator<<(std::ostream& os, const Fixed& fpn)
{
	os << fpn.toFloat();
	return (os);
}