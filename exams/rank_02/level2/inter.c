// $>./inter "padinton" "paqefwtadjetyaiytjneytjoeyjnejeyj" | cat -e
// padinto$
// $>./inter ddf6vdddewg6d4f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e
// df6ewg4$ .   k j
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
	int j = 0;
	int k = 0;

	while (s1[i])
	{
		j = i + 1;
		k = j;
		while (s1[j])
		{
			if (s1[j] != s1[i])
				s1[k++] = s1[j];
			j++;
		}
		s1[k] = '\0';
		i++;
	}
	return (s1);
}


void	inter(char *s1, char *s2)
{
	int i = 0;
	int j = 0;

	s1 = remove_dup(s1);
	s2 = remove_dup(s2);
	i = 0;
	while (s1[i])
	{
		j = 0;
		while (s2[j])
		{
			if (s1[i] == s2[j])
				write(1, &s1[i], 1);
			j++;
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
