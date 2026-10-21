#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <iomanip>
# include <vector>
# include <deque>
# include <string>
# include <cstdlib>
# include <climits>
# include <cerrno>
# include <stdexcept>
# include <cctype>
# include <sys/time.h>

struct VecPair
{
	int	small;
	int	big;
};

struct DeqPair
{
	int	small;
	int	big;
};

class PmergeMe
{
	private:
		std::vector<int>	_vec;
		std::deque<int>		_deq;
		std::vector<int>	_vecSorted;
		std::deque<int>		_deqSorted;
		double				_vecTime;
		double				_deqTime;

		bool				isValidNumber(const std::string& str) const;
		int					toInt(const std::string& str) const;
		double				getTimeUs() const;

		void				printBefore() const;
		void				printAfter() const;
		void				printTimes() const;

		std::vector<int>	sortVector(const std::vector<int>& input);
		std::vector<int>	buildVectorOrder(size_t size) const;
		void				insertVector(std::vector<int>& main, int value,
								size_t limit) const;
		size_t				findVectorPos(const std::vector<int>& main,
								int value) const;

		std::deque<int>		sortDeque(const std::deque<int>& input);
		std::deque<int>		buildDequeOrder(size_t size) const;
		void				insertDeque(std::deque<int>& main, int value,
								size_t limit) const;
		size_t				findDequePos(const std::deque<int>& main,
								int value) const;

	public:
		PmergeMe();
		PmergeMe(const PmergeMe& other);
		PmergeMe& operator=(const PmergeMe& other);
		~PmergeMe();

		void				parseInput(int argc, char **argv);
		void				run();
};

#endif
