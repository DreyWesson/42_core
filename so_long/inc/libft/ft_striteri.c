/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 12:17:26 by doduwole          #+#    #+#             */
/*   Updated: 2023/01/16 16:37:21 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int		i;

	i = 0;
	if (s == NULL || f == NULL)
		return ;
	while (s[i] != '\0')
	{
		f(i, (s + i));
		i++;
	}
}
// void	f(unsigned int i, char *c)
// {
// 	printf("%c\t%i\n", *c, i);
// }

// int	main(void)
// {
// 	ft_striteri("Drey", f);
// 	return (0);
// }
