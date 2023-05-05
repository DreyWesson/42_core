// Write a program that takes a string and reverses the case of all its letters.
// Other characters remain unchanged.
// You must display the result followed by a '\n'.
// If the number of arguments is not 1, the program displays '\n'.
// Examples :
// $>./ulstr "L'eSPrit nE peUt plUs pRogResSer s'Il staGne et sI peRsIsTent VAnIte et auto-justification." | cat -e
// l'EspRIT Ne PEuT PLuS PrOGrESsER S'iL STAgNE ET Si PErSiStENT vaNiTE ET AUTO-JUSTIFICATION.$
// $>./ulstr "S'enTOuRer dE sECreT eSt uN sIGnE De mAnQuE De coNNaiSSanCe.  " | cat -e
// s'ENtoUrER De SecREt EsT Un SigNe dE MaNqUe dE COnnAIssANcE.  $
// $>./ulstr "3:21 Ba  tOut  moUn ki Ka di KE m'en Ka fe fot" | cat -e
// 3:21 bA  ToUT  MOuN KI kA DI ke M'EN kA FE FOT$
// $>./ulstr | cat -e
// $

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
