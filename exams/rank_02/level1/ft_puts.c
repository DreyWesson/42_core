#include <unistd.h>

void	ft_puts(char*str)
{
	int i;

	i = -1;
	while (str[++i])
		write(1, str + i, 1);
}

int	main(void)
{
	ft_puts("string\n");
	return (0);
}
