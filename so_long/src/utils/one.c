/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 16:37:29 by doduwole          #+#    #+#             */
/*   Updated: 2023/08/12 16:40:02 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

int	ft_error(char *message)
{
	ft_printf("\033[1;31m" "Error\n" "\033[0m");
	ft_printf("\033[3m\033[2;37m" " %s\n" "\033[0m", message);
	return (0);
}

void	ft_warning(char *message)
{
	ft_printf("\033[1;33m" "Warning\n" "\033[0m");
	ft_printf("\033[3m\033[2;37m" " %s\n" "\033[0m", message);
}

// void	*null_error(char *message)
// {
// 	ft_printf("\033[0;31m" " Error\n %s\n" "\033[0m", message);
// 	return (0);
// }
static	int	ft_char_in_set(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	ft_trim(char const *s1, char const *set)
{
	size_t	start;

	start = 0;
	while (s1[start] && ft_char_in_set(s1[start], set))
		start++;
	return (start);
}
