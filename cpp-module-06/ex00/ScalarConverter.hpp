#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <string>

enum LiteralType
{
	TYPE_CHAR,
	TYPE_INT,
	TYPE_FLOAT,
	TYPE_DOUBLE,
	TYPE_PSEUDO_FLOAT,
	TYPE_PSEUDO_DOUBLE,
	TYPE_INVALID,
};

class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &other);
		ScalarConverter &operator=(const ScalarConverter &other);
		~ScalarConverter();
	
	public:
		static void convert(const std::string &literal);
};

#endif
