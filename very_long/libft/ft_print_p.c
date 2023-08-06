/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioduwole <ioduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 15:40:01 by ioduwole          #+#    #+#             */
/*   Updated: 2022/11/21 15:09:44 by ioduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_put_ptr(unsigned long n);

int	ft_print_p(va_list args)
{
	char					*str;
	unsigned long			n;
	int						i;

	i = 0;
	n = va_arg (args, unsigned long);
	write (1, "0x", 2);
	if (n == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	str = ft_put_ptr (n);
	if (str == NULL)
		str = "0";
	while (str[i] != '\0')
	{
		write (1, &str[i], 1);
		i++;
	}
	free (str);
	return (i);
}
