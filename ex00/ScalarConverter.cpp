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
    if (input.length() == 1) // Chars may only 1 character long. Int's are already dealt with. 
        return (true);
    else
        return (false); 
}

bool inputIsInt( std::string input )
{
    // if (input.find('.') != std::string::npos) // if there is a decimal point
    //     return (false);
    std::istringstream iss(input);
    int i;
    int result = (iss >> std::noskipws >> i && iss.eof());
    return (result); // If can be steamed into integer then return true, otherwise return false. 
}

// TODO:
static void convertInputFromInt(std::string input)
{
    int i = std::stoi(input);

    if (input[0] == '-') // if negative
        std::cout << "char: non displayable" << std::endl;
    else if (isprint(i)) // if printable and not negative
        std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;
    else // not printable
        std::cout << "char: non displayable" << std::endl;

    if (i >= INT_MIN && i <= INT_MAX) // if int is printable
        std::cout << "int: " << i << std::endl;
    else // int is not printable
        std::cout << "int: impossible" << std::endl;

    std::cout << "float: " << static_cast<float>(i) << ".0f" << std::endl;
    std::cout << "double: " << static_cast<double>(i) << ".0" << std::endl;

    return ;
}


static void convertInputFromChar(char c)
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
    if (inputIsInt(input))
        convertInputFromInt(input);
    else if (inputIsChar(input))
        convertInputFromChar(input[0]);


}