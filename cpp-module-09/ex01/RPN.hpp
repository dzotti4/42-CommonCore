#ifndef RPN_H
# define RPN_H

# include <iostream>
# include <stdexcept>
# include <stack>

class RPN
{
	public: 
		RPN();
		RPN(const RPN &other);
		RPN &operator=(const RPN &other);
		~RPN();

		int evaluate(const std::string &expr) const;
	
	private:
		bool isOperator(char c) const;
		int applyOperator(int a, int b, char op) const;
};

#endif
