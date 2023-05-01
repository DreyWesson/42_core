#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	repeat_alpha(char *str)
{
	int	j;

	while (*str)
	{
		if ((*str >= 'a' && *str <= 'z') || (*str >= 'A' && *str <= 'Z'))
		{
			if (*str >= 'a' && *str <= 'z')
				j = *str - '`';
			else if (*str >= 'A' && *str <= 'Z')
				j = *str - '@';
			while (j-- != 0)
				write(1, str, 1);
		}
		else
			write(1, str, 1);
		++str;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		repeat_alpha(argv[1]);
	write(1, "\n", 1);

}
