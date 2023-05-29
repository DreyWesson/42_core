#include <stdlib.h>
#include <stdio.h>
#include "atoi_base.h"

// https://github.com/Jcharloi/42-Exam/blob/master/ft_atoi_base.c

void trim_space(char *str, int *itr)
{
	int i;

	i = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\r'
			|| str[i] == '\t' || str[i] == '\v'
			|| str[i] == '\n' || str[i] == '\f'))
		i++;
	*itr = i;
}

char handle_sign(char *str, int *itr)
{
	int i;
	char is_neg;

	i = 0;
	is_neg = 'n';
	if (str[i] && str[i] == '-')
		is_neg = 'y';
	if (str[i] == '+' || str[i] == '-')
		i++;
	*itr = i;
	return (is_neg);
}

int	base(int c, int base)
{
	char *str = "0123456789abcdef";
	char *str2 = "0123456789ABCDEF";
	int  i = 0;

	while (i < base)
	{
		if (c == str[i] || c == str2[i])
			return (i);
		i++;
	}
	return (-1);
}


int	atoi_base(char *str, int str_base)
{
	signed int nbr;
	int i;
	char is_neg;

	i = 0;
	nbr = 0;
	trim_space(str, &i);
	is_neg = handle_sign(str, &i);
	while (base(str[i], str_base) != -1)
	{
		nbr *= str_base;
		nbr += base(str[i], str_base);
		i++;
	}
	if (is_neg == 'y')
		return (-nbr);
	return (nbr);
}

int	main(void)
{
	printf("%d\n", atoi_base("15690b80B", 13));
}
