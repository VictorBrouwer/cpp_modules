#if !defined(FIXED_H)
#define FIXED_H

#include<iostream>
#include<cmath>

class Fixed {
	private:
	int	_fpnValue;
	static const int _fracBits = 8;

	public:
	Fixed();
	Fixed(const int num);
	Fixed(const float num);
	Fixed(const Fixed &original);
	void	operator=(const Fixed& original);
	// std::ostream& operator<<(std::ostream& os, Fixed fpn);
	~Fixed();
	int getRawBits( void ) const;
	void setRawBits( int const raw );
	float toFloat( void ) const;
	int toInt( void ) const;
};

std::ostream& operator<<(std::ostream& os, const Fixed& fpn);

#endif // FIXED_H