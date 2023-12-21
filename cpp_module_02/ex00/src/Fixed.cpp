#include"../include/Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "default constructor called" << std::endl;
	_fpnValue = 0;
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
	return (this->_fpnValue >> this->_fracBits);
}

void Fixed::setRawBits( int const raw )
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_fpnValue =  raw << this->_fracBits;
}
