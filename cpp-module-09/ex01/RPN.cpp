#include "RPN.hpp"
#include <stdexcept>
#include <cctype>

RPN::RPN()
{
}

RPN::RPN(const RPN &other)
{
	(void)other;
}

RPN &RPN::operator=(const RPN &other)
{
	if (this != &other)
		(void)other;
	return (*this);
}

RPN::~RPN()
{
}

bool	RPN::isOperator(char c) const
{
	return (c == '+' || c == '-' || c == '*' || c == '/');
}

int	RPN::applyOperator(int a, int b, char op) const
{
	if (op == '+')
		return (a + b);
	if (op == '-')
		return (a - b);
	if (op == '*')
		return (a * b);
	if (op == '/')
	{
		if (b == 0)
			throw std::runtime_error("Error");
		return (a / b);
	}
	throw std::runtime_error("Error");
}

int	RPN::evaluate(const std::string &expr) const
{
	std::stack<int>	stack;
	int				a;
	int				b;

	for (std::size_t i = 0; i < expr.length(); i++)
	{
		if (std::isspace(expr[i]))
			continue ;
		if (std::isdigit(expr[i]))
		{
			stack.push(expr[i] - '0');
		}
		else if (isOperator(expr[i]))
		{
			if (stack.size() < 2)
				throw std::runtime_error("Error");
			b = stack.top();
			stack.pop();
			a = stack.top();
			stack.pop();
			stack.push(applyOperator(a, b, expr[i]));
		}
		else
			throw std::runtime_error("Error");
	}
	if (stack.size() != 1)
		throw std::runtime_error("Error");
	return (stack.top());
}
