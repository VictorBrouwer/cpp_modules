#if !defined(FIXED_H)
#define FIXED_H

#include<iostream>

class Fixed {
	private:
	int	_fpnValue;
	static const int _fracBits = 8;

	public:
	Fixed();
	Fixed(const Fixed &original);
	void	operator=(const Fixed& original);
	~Fixed();
	int getRawBits( void ) const;
	void setRawBits( int const raw );
};

#endif // FIXED_H