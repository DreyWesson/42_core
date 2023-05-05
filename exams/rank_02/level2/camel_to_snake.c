#include <unistd.h>
#include <stdio.h>

void	camel_to_snake(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		if (str[i + 1] && str[i + 1] >= 'A' && str[i + 1] <= 'Z')
		{
			write(1, "_", 1);
			str[i + 1] = str[i + 1] + 32;
		}

		i++;
	}
	write(1, "\n", 1);
}

int	main(int argc, char **argv)
{
	if (argc == 1)
		write(1, "\n", 1);
	if (argc == 2)
		camel_to_snake(argv[1]);
	return (0);
}
