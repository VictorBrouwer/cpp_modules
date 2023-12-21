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
	~Fixed();
	void	operator=(const Fixed& original);

	bool	operator<(const Fixed& other) const;
	bool	operator>(const Fixed& other) const;
	bool	operator>=(const Fixed& other) const;
	bool	operator<=(const Fixed& other) const;
	bool	operator==(const Fixed& other) const;
	bool	operator!=(const Fixed& other) const;

	Fixed	operator+(const Fixed& other) const;
	Fixed	operator-(const Fixed& other) const;
	Fixed	operator*(const Fixed& other) const;
	Fixed	operator/(const Fixed& other) const;

	Fixed	operator++(void); // prefix
	Fixed	operator-- (void); // prefix
	Fixed	operator++(int); //postfix
	Fixed	operator--(int); //postfix

	int 	getRawBits( void ) const;
	void 	setRawBits( int const raw );
	float 	toFloat( void ) const;
	int 	toInt( void ) const;

	static const Fixed&	min(const Fixed& num1, const Fixed& num2);
	static Fixed&		min(Fixed& num1, Fixed& num2);
	static const Fixed&	max(const Fixed& num1, const Fixed& num2);
	static Fixed&		max(Fixed& num1, Fixed& num2);
};

std::ostream& operator<<(std::ostream& os, const Fixed& fpn);

#endif // FIXED_H