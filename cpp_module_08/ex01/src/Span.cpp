#include "../include/Span.hpp"

// OCF

Span::Span(size_t N) : _maxLen(N), _index(0)
{
	// _vec = new std::vector<int>;
	_vec.reserve(_maxLen);
	std::cout << "Span of size " << N << " created" << std::endl;
}

Span::Span(const Span &rhs) : Span(rhs._maxLen)
{
	std::cout << "copy constructor called" << std::endl;
}

Span &Span::operator=(const Span rhs)
{
	std::cout << "assignment operator called" << std::endl;
	if (this != &rhs)
	{
		_index = rhs._index;
		_maxLen = rhs._maxLen;
		_vec = rhs._vec;
	}
	return (*this);
}

Span::~Span()
{
	std::cout << "Span destructed" << std::endl;
}


// member funcs

void Span::addNumber(int n)
{
	if (_index >= _maxLen)
		throw std::out_of_range("Span is full");
	_vec[_index++] = n;
}

void Span::addRange(std::vector<int> &range)
{
	if (_index + range.size() >= _maxLen)
		throw std::out_of_range("Span is full");
	std::vector<int>::iterator it;
	for (it = range.begin(); it < range.end(); it++)
		_vec[_index++] = *it;
}

int Span::shortestSpan() const
{
	if (_index < 1)
		throw std::out_of_range("not enough numbers to calculate span");
	int span = _vec[1] - _vec[0];
	for (size_t i = 1; i < _index; i++)
	{
		for (size_t j = 0; j < _index; j++)
		{
			if (abs(_vec[i] - _vec[j]) < span)
				span = abs(_vec[i] - _vec[j]);
		}
	}
	return span;
}

int Span::longestSpan() const
{
	if (_index < 1)
		throw std::out_of_range("not enough numbers to calculate span");
	int span = 0;
	for (size_t i = 1; i < _index; i++)
	{
		for (size_t j = 0; j < _index; j++)
		{
			if (abs(_vec[i] - _vec[j]) > span)
				span = abs(_vec[i] - _vec[j]);
		}
	}
	return span;
}

size_t Span::getIndex() const
{
	return (_index);
}

int &Span::operator[](size_t i)
{
	if (i >= _index)
		throw std::out_of_range("index out of range");
	return _vec[i];
}

std::ostream& operator<<(std::ostream& out, Span& span)
{
	for (size_t i = 0; i < span.getIndex(); i++)
		out << i << " = " << span[i] << std::endl;
	return out;
}