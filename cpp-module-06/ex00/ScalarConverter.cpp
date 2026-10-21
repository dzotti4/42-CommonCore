#include "ScalarConverter.hpp"
#include <cctype>
#include <iostream>
#include <cstdlib>
#include <limits>
#include <iomanip>

static bool isDouble(const std::string &str)
{
	size_t	i;
	int		dot_count;
	int		digit_count;

	if (str.length() == 0)
		return (false);
	i = 0;
	digit_count = 0;
	dot_count = 0;
	if (str[0] == '+' || str[0] == '-')
		i++;
	while (i < str.length())
	{
		if (!std::isdigit(str[i]) && str[i] != '.')
			return false;
		if (str[i] == '.')
			dot_count++;
		if (std::isdigit(str[i]))
			digit_count++;
		i++;
	}
	if (dot_count != 1 || digit_count == 0)
		return false;
	return true;
}

static bool isFloat(const std::string &str)
{
	size_t	i;
	int		dot_count;
	int		digit_count;

	if (str.length() == 0)
		return false;
	if (str[str.length() - 1] != 'f')
		return false;
	i = 0;
	dot_count = 0;
	digit_count = 0;
	if (str[0] == '+' || str[0] == '-')
		i++;
	while (i < str.length() - 1)
	{
		if (!std::isdigit(str[i]) && str[i] != '.')
			return false;
		if (str[i] == '.')
			dot_count++;
		if (std::isdigit(str[i]))
			digit_count++;
		i++;
	}
	if (dot_count != 1 || digit_count == 0)
		return false;
	return true;
}

static bool isInt(const std::string &str)
{
	size_t i; 

	if (str.length() == 0)
		return false;
	i = 0;
	if (str[0] == '-' || str[0] == '+')
		i++;
	if (i == str.length())
		return false;
	while (i < str.length())
	{
		if (!std::isdigit(str[i]))
			return false;
		i++;
	}
	return true;
}

static bool	isPseudoFloat(const std::string &str)
{
	return (str == "nanf" || str == "+inff" || str == "-inff");
}

static bool	isPseudoDouble(const std::string &str)
{
	return (str == "nan" || str == "+inf" || str == "-inf");
}

static LiteralType	detectType(const std::string &str)
{
	if (str.length() == 1 && !std::isdigit(str[0]))
		return (TYPE_CHAR);
	if (isPseudoFloat(str))
		return (TYPE_PSEUDO_FLOAT);
	if (isPseudoDouble(str))
		return (TYPE_PSEUDO_DOUBLE);
	if (isInt(str))
		return (TYPE_INT);
	if (isFloat(str))
		return (TYPE_FLOAT);
	if (isDouble(str))
		return (TYPE_DOUBLE);
	return (TYPE_INVALID);
}

static void	printChar(double value)
{
	if (value != value || value < 0 || value > 127)
	{
		std::cout << "char: impossible" << std::endl;
		return ;
	}
	if (!std::isprint(static_cast<int>(value)))
	{
		std::cout << "char: Non displayable" << std::endl;
		return ;
	}
	std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
}

static void	printInt(double value)
{
	if (value != value
		|| value < std::numeric_limits<int>::min()
		|| value > std::numeric_limits<int>::max())
	{
		std::cout << "int: impossible" << std::endl;
		return ;
	}
	std::cout << "int: " << static_cast<int>(value) << std::endl;
}

static void	printFloat(double value)
{
	std::cout << "float: " << std::fixed << std::setprecision(1)
		<< static_cast<float>(value) << "f" << std::endl;
}

static void printDouble(double value)
{
	std::cout << "double: " << std::fixed << std::setprecision(1)
		<< value << std::endl;
}

void ScalarConverter::convert(const std::string &literal)
{
	LiteralType	type;
	double	value;

	type = detectType(literal);
	if (type == TYPE_INVALID)
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
		return ;
	}
	if (type == TYPE_PSEUDO_FLOAT)
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << literal << std::endl;
		std::cout << "double: " << literal.substr(0, literal.length() - 1) << std::endl;
		return ;
	}
	if (type == TYPE_PSEUDO_DOUBLE)
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << literal << "f" << std::endl;
		std::cout << "double: " << literal << std::endl;
		return ;
	}
	if (type == TYPE_CHAR)
		value = static_cast<double>(literal[0]);
	else
		value = std::strtod(literal.c_str(), NULL);
	printChar(value);
	printInt(value);
	printFloat(value);
	printDouble(value);
}
