#if !defined(RPN_HPP)
#define RPN_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <stack>
#include <functional>

bool isNum(char c)
{
	return (c >= '0' && c <= '9');
}

int	charToInt(char c)
{
	return (c - '0');
}

int performOperation(char c, int x, int y)
{
	switch (c)
	{
	case '+':
		return x + y;
	case '-':
		return x - y;
	case '*':
		return x * y;
	case '/':
	{
		if (y == 0)
			throw std::logic_error("Error");
		return x / y;
	}
	default:
		throw std::logic_error("Error");
	}
}

int rpn(std::string str)
{
	int res;
	std::stack<int> st;
	for (size_t i = 0; i < str.length(); i++)
	{
		char c = str[i];
		if (isspace(c))
			continue;
		else if (isNum(c))
			st.push(charToInt(c));
		else if (st.size() >= 2)
		{
			int x = st.top();
			st.pop();
			int y = st.top();
			st.pop();
			st.push(performOperation(c, y , x));
		}
		else
			throw std::logic_error("Error");
	}
	if (st.size() == 0)
		throw std::logic_error("Error");
	res = st.top();
	return res;
}

#endif // RPN_HPP
