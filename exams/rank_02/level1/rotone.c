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
			j = *str + 1;
			if (*str >= 'a' && *str <= 'z' && j > 'z')
					j = 96 + (j - 122);
			else if (*str >= 'A' && *str <= 'Z' && j > 'Z')
				j = 64 + (j - 90);
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
		repeat_alpha(argv[1]);
	write(1, "\n", 1);

}
