#if !defined(EASYFIND_HPP)
#define EASYFIND_HPP

#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>
#include <type_traits>

template <typename T>
typename T::iterator easyfind(T& int_container, int needle)
{
	typename T::iterator it = std::find(int_container.begin(), int_container.end(), needle);
	if (it == int_container.end())
		throw std::runtime_error("element not found");
	return it;
}

#endif // EASYFIND_HPP