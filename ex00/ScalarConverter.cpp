#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void) {}

ScalarConverter::ScalarConverter( ScalarConverter const &copy)
{
	(void)copy;
}

ScalarConverter::~ScalarConverter() {}

ScalarConverter const &ScalarConverter::operator=( const ScalarConverter &copy )
{
	(void)copy;
	return(*this);
}

bool inputIsChar( std::string input )
{
    if (input.length() != 1) // Chars may only 1 character long
        return (false);
    if (!isnumber(input[0])) // 1 char long and isn't a number. Perfect for a char to exist. 
        return (true);
    else // 1 char long and is a number. 
        return (false); 
}


static void convertInputTochar(char c)
{
    std::cout << "char: '" << c << "'" << std::endl;
    std::cout << "int: " << static_cast<int>(c) << std::endl;
    std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
    std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
    return ;
}

void ScalarConverter::convert( const std::string &input )
{
    // TODO: if psuedo number
    // if is char
    if (inputIsChar(input))
        convertInputTochar(input[0]);
}