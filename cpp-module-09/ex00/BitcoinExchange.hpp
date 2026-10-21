#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>

class BitcoinExchange
{
	private:
		std::map<std::string, double>	_rates;

	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange &operator=(const BitcoinExchange &other);
		~BitcoinExchange();

		void		loadDatabase();
		double		getRate(const std::string &date) const;
		void		processInputFile(const std::string &filename) const;

		std::string	trim(const std::string &str) const;
		bool		isValidDate(const std::string &date) const;
		bool		parseValue(const std::string &str, double &value) const;
		bool		isLeapYear(int year) const;
};

#endif
