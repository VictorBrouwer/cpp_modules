#include"../include/Span.hpp"

int main()
{
	Span sp = Span(10);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	std::vector<int> vec = {4,5,6,70};
	std::cout << sp;
	sp.addRange(vec);
	std::cout << sp;
	std::cout << sp.longestSpan() << std::endl;
	return 0;
}