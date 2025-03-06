#include <iostream>
#include <string>
#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
	(void)argc;
	ScalarConverter::convert(argv[1]);

	// if (argc == 2)
	// {
	// 	try
	// 	{
	// 		std::cout << "Input: " << argv[1] << std::endl;
	// 		ScalarConverter::convert(argv[1]);
	// 	}
	// 	catch (const std::exception& e)
	// 	{
	// 		std::cerr << e.what() << std::endl;
	// 	}
	// }
	return (0);
}