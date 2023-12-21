#if !defined(SERIALIZER_hpp)
#define SERIALIZER_hpp

#include <iostream>
#include <string>
#include <cstdint>

struct Data
{
	std::string s1;
	int 		n;
	std::string s2;
};


class Serializer
{
private:
	Serializer();
	~Serializer();
	Serializer(Serializer const &other);
	Serializer &operator=(Serializer const &other);
public:
	static uintptr_t serialize(Data* ptr);
	static Data *deserialize(uintptr_t raw);
};

#endif // SERIALIZER_hpp
