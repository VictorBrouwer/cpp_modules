#if !defined(MUTANTSTACK_HPP)
#define MUTANTSTACK_HPP

#include<iostream>
#include<string>
#include<iterator>
#include<stack>

template <typename T>
class MutantStack : public std::stack<T>
{
private:
public:
	typedef typename std::stack<T>::container_type::iterator iterator;
	MutantStack() ;
	MutantStack(const MutantStack& rhs);
	MutantStack& operator=(const MutantStack& rhs);
	~MutantStack();
	iterator begin();
	iterator end();
};

template <typename T>
MutantStack<T>::MutantStack() : std::stack<T>()
{
}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack& rhs)
{
	this->c = rhs.c;
}

template <typename T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack& rhs)
{
	if (this != &rhs)
		this->c = rhs.c;
	return *this;
}

template <typename T>
MutantStack<T>::~MutantStack()
{
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
	return this->c.begin();
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end()
{
	return this->c.end();
}

#endif // MUTANTSTACK_HPP
