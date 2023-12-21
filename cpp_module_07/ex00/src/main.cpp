#include "../include/Templates.hpp"

class Awesome
{
  public:
    Awesome(void) : _n(0) {}
    Awesome( int n ) : _n( n ) {}
    Awesome & operator= (Awesome & a) { _n = a._n; return *this; }
    bool operator==( Awesome const & rhs ) const { return (this->_n == rhs._n); }
    bool operator!=( Awesome const & rhs ) const{ return (this->_n != rhs._n); }
    bool operator>( Awesome const & rhs ) const { return (this->_n > rhs._n); }
    bool operator<( Awesome const & rhs ) const { return (this->_n < rhs._n); }
    bool operator>=( Awesome const & rhs ) const { return (this->_n >= rhs._n); }
    bool operator<=( Awesome const & rhs ) const { return (this->_n <= rhs._n); }
    int get_n() const { return _n; }
  private:
    int _n;
};
std::ostream & operator<<(std::ostream & o, const Awesome &a) { o << a.get_n(); return o; }

int main(void)
{
	Awesome a(2), b(4);

        max(a, b);
        std::cout << a << " " << b << std::endl;
        std::cout << max(a, b) << std::endl;
        std::cout << min(a, b) << std::endl;
        return (0);
}

// int main()
// {
// 	int a = 2;
// 	int b = 3;
// 	float af = 2.5;
// 	float bf = 3.5;
// 	std::cout << "a = " << a << " b = " << b << std::endl;
// 	swap(a, b);
// 	std::cout << "a = " << a << " b = " << b << std::endl;
// 	std::cout << "min(a, b) = " << min(a, b) << std::endl;
// 	std::cout << "max(a, b) = " << max(a, b) << std::endl;

// 	std::cout << std::endl << "now for strings" << std::endl << std::endl;

// 	std::string c = "chaine1";
// 	std::string d = "chaine2";
// 	::swap(c, d);
// 	std::cout << "c = " << c << ", d = " << d << std::endl;
// 	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
// 	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;

// 	std::cout << std::endl << "now for floats" << std::endl << std::endl;

// 	std::cout << "af = " << af << " bf = " << bf << std::endl;
// 	swap(af, bf);
// 	std::cout << "af = " << af << " bf = " << bf << std::endl;
// 	std::cout << "min(af, bf) = " << min(af, bf) << std::endl;
// 	std::cout << "max(af, bf) = " << max(af, bf) << std::endl;
// }