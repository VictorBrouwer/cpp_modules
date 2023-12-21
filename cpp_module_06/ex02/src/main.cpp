#include "../include/Base.hpp"
#include "../include/A.hpp"
#include "../include/B.hpp"
#include "../include/C.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

Base *generate(void);
void identify(Base *p);
void identify(Base &p);

int main()
{
	Base *base = generate();
	Base &D = *base;
	Base Base_test;
	identify(base);
	identify(D);
	identify(Base_test);
	delete base;
}

Base *generate(void)
{
	srand(time(NULL));
	int random = rand() % 3;
	if (random == 0)
		return new A;
	else if (random == 1)
		return new B;
	else
		return new C;
}

void identify(Base *p)
{
	if (dynamic_cast<A *>(p) != nullptr)
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B *>(p) != nullptr)
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C *>(p) != nullptr)
		std::cout << "C" << std::endl;
	else
		std::cout << "Error" << std::endl;
}

void identify(Base &p)
{
	try
	{
		if (dynamic_cast<A *>(&p) != nullptr)
			std::cout << "A" << std::endl;
		else if (dynamic_cast<B *>(&p) != nullptr)
			std::cout << "B" << std::endl;
		else if (dynamic_cast<C *>(&p) != nullptr)
			std::cout << "C" << std::endl;
		else
			throw std::exception();
	}
	catch (std::exception &e)
	{
		std::cout << "casting failed" << std::endl;
	}
}