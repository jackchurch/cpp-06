#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void) 
{
    std::cout << "Default constructor called but isn't allowed..." << std::endl;
    std::cout << "Calling deconstructor..." << std::endl;
}

ScalarConverter::ScalarConverter( ScalarConverter const &copy)
{
	(void)copy;
}

ScalarConverter::~ScalarConverter()
{
    std::cout << "Deconstructor called." << std::endl;
}

ScalarConverter const &ScalarConverter::operator=( const ScalarConverter &copy )
{
	(void)copy;
	return(*this);
}

void    nonDisplayable(void)
{
    std::cout << "char:\tNon displayable." << std::endl;
    return ;
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
    std::istringstream iss(input);
    int i;
    int result = (iss >> std::noskipws >> i && iss.eof());
    return (result); // If can be steamed into integer then return true, otherwise return false. 
}

static void convertInputFromInt(std::string input)
{
    int i = std::stoi(input);

    // Show char
    if (input[0] == '-') // if negative
        nonDisplayable();
    else if (isprint(i)) // if printable and not negative
        std::cout << "char:\t'" << static_cast<char>(i) << "'" << std::endl;
    else // not printable
        nonDisplayable();

    // Show int
    if (i >= INT_MIN && i <= INT_MAX) // if int is printable
        std::cout << "int:\t" << i << std::endl;
    else // int is not printable
        std::cout << "int:\tPlease regard this message: Your conversion is impossible." << std::endl;

    // Show float and double
    std::cout << "float:\t" << static_cast<float>(i) << ".0f" << std::endl;
    std::cout << "double:\t" << static_cast<double>(i) << ".0" << std::endl;

    return ;
}

static void convertInputFromChar(char c)
{
    std::cout << "char:\t'" << c << "'" << std::endl;
    std::cout << "int:\t" << static_cast<int>(c) << std::endl;
    std::cout << "float:\t" << static_cast<float>(c) << ".0f" << std::endl;
    std::cout << "double:\t" << static_cast<double>(c) << ".0" << std::endl;
    return ;
}

bool inputIsFloat( std::string input )
{
    if (input.length() < 3) // floats must be 3 characters long for example: "5.f". 
        return (false);
    if (input.back() != 'f') // floats must end in 'f'. 
        return (false);
    std::string sub = input.substr(0, input.length() - 1); // Remove the 'f' from the end.

    if (sub.find('.') == std::string::npos) // Must have at least one decimal point. 
        return (false);
    
    std::istringstream iss(sub);
    float f;
    int result = (iss >> std::noskipws >> f && iss.eof());
    // std::cout << "My float: " << f << std::endl;
    return (result); // If can be steamed into float then return true, otherwise return false. 

}

bool inputIsDouble(std::string input)
{
    if (input.find('.') == std::string::npos) // Must have at least one decimal point.
        return (false);
    std::istringstream iss(input);
    double d;
    int result = (iss >> std::noskipws >> d && iss.eof());
    return (result); // If can be steamed into double then return true, otherwise return false. 
}

void convertInputFromDouble(std::string input)
{
    double d = std::stod(input);
    if (d <= 0)
        nonDisplayable();
    else if (isprint(d)) // if printable and not negative
        std::cout << "char:\t'" << static_cast<char>(d) << "'" << std::endl;
    else // not printable
        nonDisplayable();
        
    std::cout << "int:\t" << static_cast<int>(d) << std::endl;

    if (d == (int)d) // if d has no value after the decimal
        std::cout << std::fixed << std::setprecision(1);
    std::cout << "float:\t" << static_cast<float>(d) << "f" << std::endl;
    std::cout << "double:\t" << d << std::endl;
    return ;
}


void convertInputFromFloat(std::string input )
{
    std::string sub = input.substr(0, input.length() - 1); // Remove the 'f' from the end.
    // convertInputFromDouble(sub); // Not allowed: makes jack sad
    float f = std::stof(sub);
    if (f <= 0)
        nonDisplayable();
    else if (isprint(f))
        std::cout << "char:\t'" << static_cast<char>(f) << "'" << std::endl;
    else
        nonDisplayable();

    std::cout << "int:\t" << static_cast<int>(f) << std::endl;

    if (f == (int)f) // if f has no value after the decimal
        std::cout << std::fixed << std::setprecision(1);
    std::cout << "float:\t" << f << "f" << std::endl;
    std::cout << "double:\t" << static_cast<double>(f) << std::endl;

    return ;
}


bool inputIsPseudo(std::string input)
{
    if (input == "-inff" || input == "+inff" || input == "nanf"
        || input == "-inf" || input == "+inf" || input == "nan")
        return (true);
    else
        return (false);
}

void convertInputFromPseudo(std::string input)
{
    // if fake float
    if (input == "-inff" || input == "+inff" || input == "nanf")
    {        
		std::cout << "char:\tPlease regard this message: Your conversion is impossible." << std::endl;
		std::cout << "int:\tPlease regard this message: Your conversion is impossible." << std::endl;
		std::cout << "float:\t" << input << std::endl;
        std::cout << "double:\t" << input.substr(0, input.length() - 1) << std::endl;
    }
    // if fake double
    if (input == "-inf" || input == "+inf" || input == "nan")
    {
        std::cout << "char:\tPlease regard this message: Your conversion is impossible." << std::endl;
		std::cout << "int:\tPlease regard this message: Your conversion is impossible." << std::endl;
		std::cout << "float:\t" << input << "f" << std::endl;
		std::cout << "double:\t" << input << std::endl;
    }
    return ;
}

void ScalarConverter::convert( const std::string &input )
{
    if (inputIsPseudo(input))
        convertInputFromPseudo(input);
    else if (inputIsInt(input))
        convertInputFromInt(input);
    else if (inputIsChar(input))
        convertInputFromChar(input[0]);
    else if (inputIsFloat(input))
        convertInputFromFloat(input);
    else if (inputIsDouble(input))
        convertInputFromDouble(input);
    else
        throw std::invalid_argument("\n\nThis is a message to tell the user the input is invalid:\n\n\tYour input is invalid.\n\t\t[Blows raspberries at user.]\n\n");
    return ;
}