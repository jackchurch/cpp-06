#include "Serializer.hpp"

// Constructor
Serializer::Serializer(void) {}

// Deconstructor
Serializer::~Serializer(void) {}

// = Overload
Serializer &Serializer::operator=(Serializer const & orignal)
{
    if (this == &orignal) // Making g++ happy
        return (*this);
    return (*this);
}

// Copy constructor
Serializer::Serializer( Serializer const &orignal)
{
	*this = orignal;
}

uintptr_t Serializer::serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data* Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
}
