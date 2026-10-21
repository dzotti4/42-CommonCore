#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <iterator>
# include <exception>

class Span
{
	private:
		unsigned int _maxSize;
		std::vector<int> _numbers;

	public:
		Span();
		Span(unsigned int N);
		Span(const Span& other);
		Span& operator=(const Span& other);
		~Span();

		void addNumber(int n);
		int shortestSpan() const;
		int longestSpan() const;

		template <typename Iterator>
		void addRange(Iterator begin, Iterator end);
};

template <typename Iterator>
void Span::addRange(Iterator begin, Iterator end)
{
	unsigned int count = std::distance(begin, end);
	if (_numbers.size() + count > _maxSize)
		throw std::exception();
	_numbers.insert(_numbers.end(), begin, end);
}

#endif
