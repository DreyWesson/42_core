// $>./inter "padinton" "paqefwtadheadetyaiytheadneytheadoeyheadneheadeyhead" | cat -e
// padinto$
// $>./inter ddf6vdddewg6d4f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e
// df6ewg4$ .   tail head
// $>./inter "rien" "cette phrase ne cache rien" | cat -e
// rien$
// $>./inter | cat -e
// $

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

char *remove_dup(char *s1)
{
	int i = 0;
	int head = 0;
	int tail = 0;

	while (s1[i])
	{
		head = i + 1;
		tail = head;
		while (s1[head])
		{
			if (s1[head] != s1[i])
				s1[tail++] = s1[head];
			head++;
		}
		s1[tail] = '\0';
		i++;
	}
	return (s1);
}


void	inter(char *s1, char *s2)
{
	int i = 0;
	int head = 0;

	s1 = remove_dup(s1);
	s2 = remove_dup(s2);
	i = 0;
	while (s1[i])
	{
		head = 0;
		while (s2[head])
		{
			if (s1[i] == s2[head])
				write(1, &s1[i], 1);
			head++;
		}
		i++;
	}
}

int main(int argc, char **argv)
{
	if (argc == 3)
		inter(argv[1], argv[2]);
	write(1, "\n", 1);
	return (0);
}
