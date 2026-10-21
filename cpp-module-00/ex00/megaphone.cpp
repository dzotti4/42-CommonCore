#include <iostream>
#include <cctype>

static void	print_upper(const char *s)
{
	int j = 0;

	while (s[j])
	{
		unsigned char c = static_cast<unsigned char>(s[j]);
		std::cout << static_cast<char>(std::toupper(c));
		j++;
	}
}

int main(int ac, char **av)
{
	int	i;

	if (ac == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return 0;
	}
	for (i = 1; i < ac; i++)
	{
	print_upper(av[i]);
		if (i + 1 < ac)
			std::cout << " ";
	}
	std::cout << std::endl;
	return 0;
}
