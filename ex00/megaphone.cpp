#include <iostream>
#include <string>

int	main(int argc, char *argv[])
{
	int	i;
	int	j;

	i = 1;
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" <<std::endl;
		return (0);
	}
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			std::cout << (char) toupper(argv[i][j]);
			j++;
		}
		i++;
	}
	std::cout << '\n';
	return (0);
}
