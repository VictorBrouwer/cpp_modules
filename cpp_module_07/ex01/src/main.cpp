#include "../include/Iter.hpp"

template <typename T>
void print(T &x)
{
	std::cout << x << std::endl;
}

template <typename T>
void add_one(T &x)
{
	x++;
}

int main()
{
	int int_array[] = {1, 2, 3, 4, 5};
	double double_array[] = {1.1, 2.2, 3.3, 4.4, 5.5};
	std::string string_array[] = {"one", "two", "three", "four", "five"};
	iter(int_array, 5, print<int>);
	iter(double_array, 5, print<double>);
	iter(string_array, 5, print<std::string>);
	iter(int_array, 5, add_one<int>);
	iter(double_array, 5, add_one<double>);
	iter(int_array, 5, print<int>);
	iter(double_array, 5, print<double>);
	return 0;
}

// class Awesome
// {
//   public:
//     Awesome( void ) : _n( 42 ) { return; }
//     int get( void ) const { return this->_n; }
//   private:
//     int _n;
// };

// std::ostream & operator<<( std::ostream & o, Awesome const & rhs )
// {
//   o << rhs.get();
//   return o;
// }

// template< typename T >
// void print( T& x )
// {
//   std::cout << x << std::endl;
//   return;
// }

// int main() {
//   int tab[] = { 0, 1, 2, 3, 4 };
//   Awesome tab2[5];

//   iter( tab, 5, print<const int> );
//   iter( tab2, 5, print<Awesome> );

//   return 0;
// }
