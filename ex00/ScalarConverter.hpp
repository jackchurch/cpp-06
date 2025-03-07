#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include <cerrno>
#include <climits>
#include <cfloat>
#include <cmath>
#include <limits>
#include <sstream>

class ScalarConverter {
public:
    ~ScalarConverter ();
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
    ScalarConverter const &operator=(const ScalarConverter &orignal);
};

#endif