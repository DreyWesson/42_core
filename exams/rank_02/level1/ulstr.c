#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	ulstr(char *str)
{
	int	j;

	while (*str)
	{
		if (*str >= 'a' && *str <= 'z')
		{
			j = *str - 32;
			write(1, &j, 1);
		}
		else if ((*str >= 'A' && *str <= 'Z'))
		{
			j = *str + 32;
			write(1, &j, 1);
		}
		else
			write(1, str, 1);
		++str;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		ulstr(argv[1]);
	write(1, "\n", 1);

}
