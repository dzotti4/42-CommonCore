#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
	_vecTime = 0.0;
	_deqTime = 0.0;
}

PmergeMe::PmergeMe(const PmergeMe& other)
{
	*this = other;
}

PmergeMe&	PmergeMe::operator=(const PmergeMe& other)
{
	if (this != &other)
	{
		_vec = other._vec;
		_deq = other._deq;
		_vecSorted = other._vecSorted;
		_deqSorted = other._deqSorted;
		_vecTime = other._vecTime;
		_deqTime = other._deqTime;
	}
	return (*this);
}

PmergeMe::~PmergeMe()
{
}

bool	PmergeMe::isValidNumber(const std::string& str) const
{
	size_t	i;

	if (str.empty())
		return (false);
	i = 0;
	while (i < str.length())
	{
		if (!std::isdigit(static_cast<unsigned char>(str[i])))
			return (false);
		i++;
	}
	return (true);
}

int	PmergeMe::toInt(const std::string& str) const
{
	long	value;
	char	*end;

	value = std::strtol(str.c_str(), &end, 10);
	if (*end != '\0')
		throw std::runtime_error("Error");
	if (value <= 0 || value > INT_MAX)
		throw std::runtime_error("Error");
	return (static_cast<int>(value));
}

void	PmergeMe::parseInput(int argc, char **argv)
{
	int			i;
	int			value;
	std::string	arg;

	if (argc < 2)
		throw std::runtime_error("Error");
	i = 1;
	while (i < argc)
	{
		arg = argv[i];
		if (!isValidNumber(arg))
			throw std::runtime_error("Error");
		value = toInt(arg);
		_vec.push_back(value);
		_deq.push_back(value);
		i++;
	}
}

double	PmergeMe::getTimeUs() const
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000000.0 + tv.tv_usec);
}

void	PmergeMe::run()
{
	double	start;
	double	end;

	printBefore();
	start = getTimeUs();
	_vecSorted = sortVector(_vec);
	end = getTimeUs();
	_vecTime = end - start;
	start = getTimeUs();
	_deqSorted = sortDeque(_deq);
	end = getTimeUs();
	_deqTime = end - start;
	printAfter();
	printTimes();
}

size_t	PmergeMe::findVectorPos(const std::vector<int>& main, int value) const
{
	size_t	i;

	i = 0;
	while (i < main.size())
	{
		if (main[i] == value)
			return (i);
		i++;
	}
	return (main.size());
}

void	PmergeMe::insertVector(std::vector<int>& main, int value,
	size_t limit) const
{
	size_t	left;
	size_t	right;
	size_t	mid;

	left = 0;
	right = limit;
	while (left < right)
	{
		mid = left + (right - left) / 2;
		if (value < main[mid])
			right = mid;
		else
			left = mid + 1;
	}
	main.insert(main.begin() + left, value);
}

std::vector<int>	PmergeMe::buildVectorOrder(size_t size) const
{
	std::vector<int>	order;
	size_t				prev;
	size_t				curr;
	size_t				next;
	size_t				i;

	prev = 1;
	curr = 3;
	while (prev < size)
	{
		i = curr;
		if (i > size)
			i = size;
		while (i > prev)
		{
			order.push_back(static_cast<int>(i - 1));
			i--;
		}
		next = curr + (2 * prev);
		prev = curr;
		curr = next;
	}
	return (order);
}

std::vector<int>	PmergeMe::sortVector(const std::vector<int>& input)
{
	std::vector<VecPair>	pairs;
	std::vector<int>	bigs;
	std::vector<int>	main;
	std::vector<int>	order;
	VecPair			pair;
	size_t			i;
	size_t			pos;
	int				odd;

	if (input.size() <= 1)
		return (input);
	odd = -1;
	i = 0;
	while (i + 1 < input.size())
	{
		if (input[i] < input[i + 1])
		{
			pair.small = input[i];
			pair.big = input[i + 1];
		}
		else
		{
			pair.small = input[i + 1];
			pair.big = input[i];
		}
		pairs.push_back(pair);
		bigs.push_back(pair.big);
		i += 2;
	}
	if (i < input.size())
		odd = input[i];
	main = sortVector(bigs);
	i = 0;
	while (i < main.size())
	{
		pos = findVectorPos(bigs, main[i]);
		if (pos < pairs.size())
		{
			pair = pairs[pos];
			pairs.erase(pairs.begin() + pos);
			pairs.insert(pairs.begin() + i, pair);
			bigs.erase(bigs.begin() + pos);
			bigs.insert(bigs.begin() + i, main[i]);
		}
		i++;
	}
	if (!pairs.empty())
		main.insert(main.begin(), pairs[0].small);
	order = buildVectorOrder(pairs.size());
	i = 0;
	while (i < order.size())
	{
		pos = static_cast<size_t>(order[i]);
		if (pos < pairs.size())
			insertVector(main, pairs[pos].small,
				findVectorPos(main, pairs[pos].big));
		i++;
	}
	if (odd != -1)
		insertVector(main, odd, main.size());
	return (main);
}

size_t	PmergeMe::findDequePos(const std::deque<int>& main, int value) const
{
	size_t	i;

	i = 0;
	while (i < main.size())
	{
		if (main[i] == value)
			return (i);
		i++;
	}
	return (main.size());
}

void	PmergeMe::insertDeque(std::deque<int>& main, int value,
	size_t limit) const
{
	size_t	left;
	size_t	right;
	size_t	mid;

	left = 0;
	right = limit;
	while (left < right)
	{
		mid = left + (right - left) / 2;
		if (value < main[mid])
			right = mid;
		else
			left = mid + 1;
	}
	main.insert(main.begin() + left, value);
}

std::deque<int>	PmergeMe::buildDequeOrder(size_t size) const
{
	std::deque<int>	order;
	size_t			prev;
	size_t			curr;
	size_t			next;
	size_t			i;

	prev = 1;
	curr = 3;
	while (prev < size)
	{
		i = curr;
		if (i > size)
			i = size;
		while (i > prev)
		{
			order.push_back(static_cast<int>(i - 1));
			i--;
		}
		next = curr + (2 * prev);
		prev = curr;
		curr = next;
	}
	return (order);
}

std::deque<int>	PmergeMe::sortDeque(const std::deque<int>& input)
{
	std::deque<DeqPair>	pairs;
	std::deque<int>		bigs;
	std::deque<int>		main;
	std::deque<int>		order;
	DeqPair			pair;
	size_t			i;
	size_t			pos;
	int				odd;

	if (input.size() <= 1)
		return (input);
	odd = -1;
	i = 0;
	while (i + 1 < input.size())
	{
		if (input[i] < input[i + 1])
		{
			pair.small = input[i];
			pair.big = input[i + 1];
		}
		else
		{
			pair.small = input[i + 1];
			pair.big = input[i];
		}
		pairs.push_back(pair);
		bigs.push_back(pair.big);
		i += 2;
	}
	if (i < input.size())
		odd = input[i];
	main = sortDeque(bigs);
	i = 0;
	while (i < main.size())
	{
		pos = findDequePos(bigs, main[i]);
		if (pos < pairs.size())
		{
			pair = pairs[pos];
			pairs.erase(pairs.begin() + pos);
			pairs.insert(pairs.begin() + i, pair);
			bigs.erase(bigs.begin() + pos);
			bigs.insert(bigs.begin() + i, main[i]);
		}
		i++;
	}
	if (!pairs.empty())
		main.insert(main.begin(), pairs[0].small);
	order = buildDequeOrder(pairs.size());
	i = 0;
	while (i < order.size())
	{
		pos = static_cast<size_t>(order[i]);
		if (pos < pairs.size())
			insertDeque(main, pairs[pos].small,
				findDequePos(main, pairs[pos].big));
		i++;
	}
	if (odd != -1)
		insertDeque(main, odd, main.size());
	return (main);
}

void	PmergeMe::printBefore() const
{
	size_t	i;

	std::cout << "Before: ";
	i = 0;
	while (i < _vec.size())
	{
		std::cout << _vec[i];
		if (i + 1 < _vec.size())
			std::cout << " ";
		i++;
	}
	std::cout << std::endl;
}

void	PmergeMe::printAfter() const
{
	size_t	i;

	std::cout << "After: ";
	i = 0;
	while (i < _vecSorted.size())
	{
		std::cout << _vecSorted[i];
		if (i + 1 < _vecSorted.size())
			std::cout << " ";
		i++;
	}
	std::cout << std::endl;
}

void	PmergeMe::printTimes() const
{
	std::cout << std::fixed << std::setprecision(5);
	std::cout << "Time to process a range of " << _vec.size();
	std::cout << " elements with std::vector : ";
	std::cout << _vecTime << " us" << std::endl;
	std::cout << "Time to process a range of " << _deq.size();
	std::cout << " elements with std::deque : ";
	std::cout << _deqTime << " us" << std::endl;
}
