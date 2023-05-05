#include <unistd.h>
#include <stdio.h>

void	snake_to_camel(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '_')
			write(1, &str[i], 1);
		else
			str[i + 1] = str[i + 1] - 32;
		i++;
	}
	write(1, "\n", 1);
}

int	main(int argc, char **argv)
{
	if (argc == 1)
		write(1, "\n", 1);
	if (argc == 2)
		snake_to_camel(argv[1]);
	return (0);
}
