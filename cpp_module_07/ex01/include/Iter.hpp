#include <iostream>
#include <string>

template<typename T, typename F>
void iter(T* arr, size_t len, F f)
{
	if (!arr)
		return ;
	for (size_t i = 0; i < len; i++)
		f(arr[i]);
}