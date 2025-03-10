#include "Serializer.hpp"

void    printOut(Data d)
{
    std::cout << "\t\tchar:\t" << d.c << std::endl;
    std::cout << "\t\tint:\t" << d.i << std::endl;
    std::cout << "\t\tstring:\t" << d.s << std::endl;
    std::cout << std::endl;
}

// Reminder to Jack, we arn't actually serlising data. Just casting with a class called Serlizer. 

int main(void)
{
    Data    input;
    Data*   output;

    std::cout << std::endl;
    std::cout << "Creat data in 'input' struct..." << std::endl;
    input.c = 'a';
    input.i = 1;
    input.s = "My first sring";
    std::cout << "Address of data:\t" << &input << std::endl;
    printOut(input);

    std::cout << "Serializing 'input'..." << std::endl;
    uintptr_t   hidden = Serializer::serialize(&input);
    std::cout <<"uintptr_t address: " << &hidden << std::endl;
    std::cout << std::endl;

    std::cout << "De-Serializing serlized data into new struct 'output'..." << std::endl;
    output = Serializer::deserialize(hidden);
    std::cout << "Address of data:\t" << &output << std::endl;
    printOut(*output);

    std::cout << "Check first struct is still there at the origal address..." << std::endl;
    std::cout << "Address of data:\t" << &input << std::endl;
    printOut(input);

    return (0);
}