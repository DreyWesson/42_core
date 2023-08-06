/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioduwole <ioduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 15:11:02 by ioduwole          #+#    #+#             */
/*   Updated: 2022/11/21 15:17:41 by ioduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_puthexi(unsigned int n, char c);
char	*ft_utoa(unsigned int n);

int	ft_print_c(va_list args)
{
	char	c;

	c = va_arg(args, int);
	write (1, &c, 1);
	return (1);
}

int	ft_print_s(va_list args)
{
	char	*str;
	int		i;

	i = 0;
	str = va_arg (args, char *);
	if (!str)
		str = "(null)";
	while (str[i] != '\0')
	{
		write (1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_print_i(va_list args)
{
	char	*str;
	int		n;
	int		i;

	i = 0;
	n = va_arg (args, int);
	str = ft_itoa (n);
	if (!str)
		str = "(null)";
	while (str[i] != '\0')
	{
		write (1, &str[i], 1);
		i++;
	}
	free (str);
	return (i);
}

int	ft_print_u(va_list args)
{
	char					*str;
	unsigned int			n;
	int						i;

	n = va_arg (args, unsigned int);
	str = ft_utoa (n);
	if (!str)
		str = "(null)";
	i = 0;
	while (str[i] != '\0' )
	{
		write(1, &str[i], 1);
		i++;
	}
	free (str);
	return (i);
}

int	ft_print_x(va_list args, char c)
{
	char					*str;
	unsigned int			n;
	int						i;

	i = 0;
	n = va_arg (args, unsigned int);
	str = ft_puthexi (n, c);
	if (!str)
		str = "(null)";
	while (str[i] != '\0')
	{
		write (1, &str[i], 1);
			i++;
	}
	free (str);
	return (i);
}
