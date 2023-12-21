#if !defined(ARRAY_HPP)
#define ARRAY_HPP

#include <iostream>
#include <string>

template <typename T> 
class Array
{
public:
	Array() { _array = new T[0]; _size = 0; };
	Array(unsigned int n) { _array = new T[n]; _size = n; };
	Array(Array const &rhs)
	{
		_array = new T[rhs._size];
		for (unsigned int i = 0; i < rhs._size; i++)
			_array[i] = rhs._array[i];
		_size = rhs._size;
	};
	Array &operator=(Array const &rhs)
	{
		if (this != &rhs)
		{
			delete[] _array;
			_array = new T[rhs._size];
			for (unsigned int i = 0; i < rhs._size; i++)
				_array[i] = rhs._array[i];
			_size = rhs._size;
		}
		return *this;
	};
	~Array() { delete[] _array; };
	unsigned int size() const { return _size; };
	T &operator[](unsigned int i)
	{
		if (i >= _size)
			throw std::out_of_range("Out of range");
		return _array[i];
	}
private:
	unsigned int _size;
	T *_array;
};

#endif // ARRAY_HPP
