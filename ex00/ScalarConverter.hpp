#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <sstream>
#include <iomanip>

class ScalarConverter {
public:
    ~ScalarConverter ();
    ScalarConverter const &operator=(const ScalarConverter &orignal);

	static void convert(const std::string &input);

    class InvalidInput : public std::exception
	{
	public:
		const char* what() const throw()
		{
			return ("Invalid input");
		}
	};

private:
    ScalarConverter();
    ScalarConverter(const ScalarConverter &orignal);
};

#endif