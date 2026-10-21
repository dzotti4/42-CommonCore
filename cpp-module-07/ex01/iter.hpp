#ifndef ITER_HPP
# define ITER_HPP

# include <cstddef>
# include <iostream>
# include <string>

template <typename T>
void	iter(T *array, const std::size_t length, void (*func)(T &))
{
	std::size_t i;

	if (!array || !func)
		return ;
	i = 0;
	while (i < length)
	{
		func(array[i]);
		i++;
	}
}

template <typename T>
void	iter(const T *array, const std::size_t length, void (*func)(const T &))
{
	std::size_t i;

	if (!array || !func)
		return ;
	i = 0;
	while (i < length)
	{
		func(array[i]);
		i++;
	}	
}

#endif
