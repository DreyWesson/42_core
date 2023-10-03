/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 13:57:00 by doduwole          #+#    #+#             */
/*   Updated: 2023/09/29 13:57:09 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	is_digit(char *str)
{
	char	tmp;

	while (*str)
	{
		tmp = *str++;
		if (tmp < 48 || tmp > 57)
			return (2);
	}
	return (0);
}

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 != '\0' && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*(char *)s1 - *(char *)s2);
}

int	ft_atoi(const char *str)
{
	long	i;
	long	nbr;
	int		is_neg;

	i = 0;
	nbr = 0;
	is_neg = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] != '\0' && str[i] == '-')
		is_neg = 1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] != '\0' && (str[i] >= '0' && str[i] <= '9'))
	{
		nbr = (nbr * 10) + (str[i] - '0');
		i++;
	}
	if (is_neg == 1)
		return (-nbr);
	return (nbr);
}

int	ft_error(char *message)
{
	printf("\033[1;31m""Error\n""\033[0m");
	printf("\033[3m\033[2;37m"" %s\n""\033[0m", message);
	return (0);
}