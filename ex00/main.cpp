#include <iostream>
#include <string>
#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
	(void)argc;

	if (argc != 2)
	{
		std::cout << "Invalid number of arguments." << std::endl;
		std::cout << "Suitable argumens are:" << std::endl;
		std::cout << "\t(1) A single char." << std::endl;
		std::cout << "\t(2) An integer." << std::endl;
		std::cout << "\t(3) A double." << std::endl;
		std::cout << "\t(4) A float in non-scientfic form. ie: 5.0f is allowed -even 5.f because people are lasy- but 5.0e-2 is not allowed." << std::endl;
		std::cout << "\t(5) Varous pseudo numbers such as nan, nanf, +inff, (look at the code for more).\n" << std::endl;
		return (1);
	}

	try
	{
		ScalarConverter::convert(argv[1]);
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	return (0);
}