// $>./wdmatch "faya" "fgvvfdxcacpolhyghbreda" | cat -e
// faya$
// $>./wdmatch "faya" "fgvvfdxcacpolhyghbred" | cat -e
// $
// $>./wdmatch "quarante deux" "qfqfsudf arzgsayns tsregfdgs sjytdekuoixq " | cat -e
// quarante deux$
// $>./wdmatch "error" rrerrrfiiljdfxjyuifrrvcoojh | cat -e
// $
// $>./wdmatch | cat -e
// $

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

char *wdmatch(char *s1, char *s2)
{
	int i = 0;
	int j = 0;
	int size = 0;

	while (s1[i] != '\0' && s2[j] != '\0')
	{
		if (s1[i] && s1[i] == s2[j])
			i++;
		j++;

	}
	while (s1[++size]);
	if (i == size)
	{
		i = 0;
		while (s1[i])
			write(1, &s1[i++], 1);
	}
	return (s1);
}

int main(int argc, char **argv)
{
	if (argc == 3)
		wdmatch(argv[1], argv[2]);
	write(1, "\n", 1);
	return (0);
}