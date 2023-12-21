#if !defined(SPAN_HPP)
#define SPAN_HPP

#include <iostream>
#include <string>
#include <vector>
#include <iterator>

class Span
{
private:
	size_t				_maxLen;
	std::vector<int>	_vec;
	size_t				_index;
public:
	Span(size_t N);
	Span(const Span &rhs);
	Span &operator=(const Span rhs);
	int &operator[](size_t i);
	~Span();
	void addNumber(int n);
	void addRange(std::vector<int> &range);
	size_t getIndex() const;
	int shortestSpan() const;
	int longestSpan()const;
};
	
std::ostream& operator<<(std::ostream& out, Span &rhs);


#endif // SPAN_HPP
