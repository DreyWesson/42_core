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

void	print(char *s1, char *s2)
{
	int i = 0;
	int j = 0;

	while (s1[i])
		write(1, &s1[i++], 1);
	while (s2[j])
		write(1, &s2[j++], 1);
}

void	remove_dup_2(char *s1, char *s2)
{
	int i = 0;
	int j;
	int k;

	s1 = remove_dup(s1);
	s2 = remove_dup(s2);
	while (s1[i])
	{
		j = 0;
		k = 0;
		while (s2[j])
		{
			if (s1[i] != s2[j])
				s2[k++] = s2[j];
			j++;
		}
		s2[k] = '\0';
		i++;
	}
	print(s1, s2);
}


void	un(char *s1, char *s2)
{

	remove_dup_2(s1, s2);
}

int main(int argc, char **argv)
{
	if (argc == 3)
		un(argv[1], argv[2]);
	write(1, "\n", 1);
	return (0);
}