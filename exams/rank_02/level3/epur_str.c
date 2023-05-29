// loop through and remove all strange char till u see alphabet or fullstop
// s[i] == "," || s[i] >= "."
// void	skip(const char *s)
// {
// 	int i;

// 	i = 0;
// 	while (s[i])
// 	{
// 		if (!(s[i] >= 65 && s[i] <= 90) || !(s[i] >= 97 && s[i] <= 122))
// 			break ;
// 		i++;
// 	}
// }

// void	print(const char *s)
// {
// 	int i;

// 	i = 0;
// 	while (s[i])
// 	{
		// if ((s[i] >= 65 && s[i] <= 90) || (s[i] >= 97 && s[i] <= 122 ))
		// {
		// 	write(1, &s[i],1);
		// }
// 		i++;
// 	}
// }
#include <unistd.h>

int main(int argc, char *argv[])
{
	int i;
	int delimiter;
	char *str;

	i = 0;
	str = argv[1];
	delimiter = 0;
	if (argc == 2)
	{
		while (str[i])
		{
			if (str[i] == ' ' || str[i] == '\t')
				delimiter++;
			if (str[i] != ' ' && str[i] != '\t')
			{
				if (delimiter)
					write(1, " ", 1);
				delimiter = 0;
				write(1, &str[i], 1);
			}
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}