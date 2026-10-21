#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <stdexcept>
#include <cctype>

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) : _rates(other._rates)
{
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this != &other)
		_rates = other._rates;
	return (*this);
}

BitcoinExchange::~BitcoinExchange()
{
}

void	BitcoinExchange::loadDatabase()
{
	std::ifstream	file("data.csv");
	std::string		line;
	std::string		date;
	std::string		rate;
	std::size_t		pos;
	double			rate_double;
	char			*endptr;

	if (!file)
		throw std::runtime_error("Error: could not open database.");
	while (std::getline(file, line))
	{
		if (line.empty())
			continue ;
		if (line == "date,exchange_rate")
			continue ;
		pos = line.find(',');
		if (pos == std::string::npos)
			throw std::runtime_error("Error: bad database line.");
		date = line.substr(0, pos);
		rate = line.substr(pos + 1);
		if (date.empty() || rate.empty())
			throw std::runtime_error("Error: bad database line.");
		if (!isValidDate(date))
			throw std::runtime_error("Error: invalid date in database.");
		rate_double = std::strtod(rate.c_str(), &endptr);
		if (*endptr != '\0')
			throw std::runtime_error("Error: invalid rate in database.");
		_rates[date] = rate_double;
	}
	if (_rates.empty())
		throw std::runtime_error("Error: database is empty.");
}

double	BitcoinExchange::getRate(const std::string &date) const
{
	std::map<std::string, double>::const_iterator	it;

	if (_rates.empty())
		throw std::runtime_error("Error: database is empty.");
	it = _rates.lower_bound(date);
	// match
	if (it != _rates.end() && it->first == date)
		return (it->second);
	//date > alles
	if (it == _rates.end())
	{
		it--;
		return (it->second);
	}
	// date < alles
	if (it == _rates.begin())
		throw std::runtime_error("Error: no earlier date in database.");
	// eerst kleine datum
	it--;
	return (it->second);
}

void	BitcoinExchange::processInputFile(const std::string &filename) const
{
	std::ifstream	file(filename.c_str());
	std::string		line;
	std::string		date;
	std::string		value_str;
	std::size_t		pos;
	double			value;
	double			rate;

	if (!file)
		throw std::runtime_error("Error: could not open file.");
	while (std::getline(file, line))
	{
		if (line.empty())
			continue ;
		if (line == "date | value")
			continue ;
		pos = line.find('|');
		if (pos == std::string::npos)
		{
			std::cout << "Error: bad input => " << line << std::endl;
			continue ;
		}
		date = trim(line.substr(0, pos));
		value_str = trim(line.substr(pos + 1));
		if (!isValidDate(date))
		{
			std::cout << "Error: bad input => " << line << std::endl;
			continue ;
		}
		if (!parseValue(value_str, value))
		{
			std::cout << "Error: bad input => " << line << std::endl;
			continue ;
		}
		if (value < 0)
		{
			std::cout << "Error: not a positive number." << std::endl;
			continue ;
		}
		if (value > 1000)
		{
			std::cout << "Error: too large a number." << std::endl;
			continue ;
		}
		try
		{
			rate = getRate(date);
			std::cout << date << " => " << value << " = " << value * rate << std::endl;
		}
		catch (const std::exception &)
		{
			std::cout << "Error: bad input => " << line << std::endl;
		}
	}
}

std::string	BitcoinExchange::trim(const std::string &str) const
{
	std::size_t	start;
	std::size_t	end;

	start = 0;
	while (start < str.length() && std::isspace(static_cast<unsigned char>(str[start])))
		start++;
	if (start == str.length())
		return ("");
	end = str.length() - 1;
	while (end > start && std::isspace(static_cast<unsigned char>(str[end])))
		end--;
	return (str.substr(start, end - start + 1));
}

bool	BitcoinExchange::parseValue(const std::string &str, double &value) const
{
	char	*endptr;

	if (str.empty())
		return (false);
	value = std::strtod(str.c_str(), &endptr);
	if (*endptr != '\0')
		return (false);
	return (true);
}

bool	BitcoinExchange::isLeapYear(int year) const
{
	if (year % 400 == 0)
		return (true);
	if (year % 100 == 0)
		return (false);
	if (year % 4 == 0)
		return (true);
	return (false);
}

bool	BitcoinExchange::isValidDate(const std::string &date) const
{
	int		year;
	int		month;
	int		day;
	int		days_in_month[12];
	std::size_t	i;

	if (date.length() != 10)
		return (false);
	if (date[4] != '-' || date[7] != '-')
		return (false);
	i = 0;
	while (i < date.length())
	{
		if (i == 4 || i == 7)
		{
			i++;
			continue ;
		}
		if (!std::isdigit(static_cast<unsigned char>(date[i])))
			return (false);
		i++;
	}
	year = std::atoi(date.substr(0, 4).c_str());
	month = std::atoi(date.substr(5, 2).c_str());
	day = std::atoi(date.substr(8, 2).c_str());
	if (month < 1 || month > 12)
		return (false);
	days_in_month[0] = 31;
	days_in_month[1] = 28;
	days_in_month[2] = 31;
	days_in_month[3] = 30;
	days_in_month[4] = 31;
	days_in_month[5] = 30;
	days_in_month[6] = 31;
	days_in_month[7] = 31;
	days_in_month[8] = 30;
	days_in_month[9] = 31;
	days_in_month[10] = 30;
	days_in_month[11] = 31;
	if (isLeapYear(year))
		days_in_month[1] = 29;
	if (day < 1 || day > days_in_month[month - 1])
		return (false);
	return (true);
}
