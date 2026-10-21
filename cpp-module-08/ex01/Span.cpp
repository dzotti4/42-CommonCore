#include "Span.hpp"
#include <exception>
#include <algorithm>

Span::Span() : _maxSize(0)
{
}

Span::Span(unsigned int N) : _maxSize(N)
{
}

Span::Span(const Span& other) : _maxSize(other._maxSize), _numbers(other._numbers)
{
}

Span& Span::operator=(const Span& other)
{
	if (this != &other)
	{
		_maxSize = other._maxSize;
		_numbers = other._numbers;
	}
	return (*this);
}

Span::~Span()
{
}

void	Span::addNumber(int n)
{
	if (_numbers.size() >= _maxSize)
		throw std::exception();
	_numbers.push_back(n);
}

int	Span::longestSpan() const
{
	if (_numbers.size() < 2)
		throw std::exception();

	std::vector<int>::const_iterator min_it;
	std::vector<int>::const_iterator max_it;

	min_it = std::min_element(_numbers.begin(), _numbers.end());
	max_it = std::max_element(_numbers.begin(), _numbers.end());
	
	return (*max_it - *min_it);
}

int Span::shortestSpan() const
{
	if (_numbers.size() < 2)
		throw std::exception();

	std::vector<int> _copy;
	std::vector<int>::iterator it;
	std::vector<int>::iterator next;

	int shortest;
	int current;

	_copy = _numbers;
	std::sort(_copy.begin(), _copy.end());
	
	it = _copy.begin();
	next = it;
	next++;
	shortest = *next - *it;

	while (next != _copy.end())
	{	

		current = *next - *it;
		if (current < shortest)
			shortest = current;
		++it;
		++next;
	}
	return (shortest);
}
