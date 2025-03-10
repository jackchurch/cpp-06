#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include <iostream>

struct Data
{
    int         i;
    char        c;
    std::string s;
};

class Serializer
{
public:
    static uintptr_t serialize(Data* ptr);
    static Data* deserialize(uintptr_t raw);
	~Serializer (void);
	Serializer &operator=(Serializer const & orignal);

private:
	Serializer (void);
	Serializer(const Serializer& orignal);
};

#endif