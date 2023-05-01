#include <unistd.h>
#include <stdio.h>

void	s_n_r(char**argv)
{
	int i = -1;

	if (argv[2][1] || argv[3][1])
		return ;
	while (argv[1][++i])
	{
		if (argv[1][i] == argv[2][0])
			 argv[1][i] =  argv[3][0];
		write(1, &argv[1][i], 1);
	}
}

int	main(int argc, char **argv)
{
	if (argc == 4)
		s_n_r(argv);
	write(1, "\n", 1);
	return (0);
}
