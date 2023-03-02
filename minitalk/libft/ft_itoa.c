/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 09:13:59 by doduwole          #+#    #+#             */
/*   Updated: 2023/01/26 19:03:05 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_nbrlen(int n)
{
	int	i;

	i = 0;
	if (n <= 0)
		i = 1;
	while (n)
	{
		n /= 10;
		++i;
	}
	return (i);
}

void	lesser_num(int *n, char *ptr, int *len)
{
	if (*n == 0)
		ptr[0] = '0';
	if (*n < 0)
	{
		ptr[0] = '-';
		if (*n == -2147483648)
		{
			ptr[--(*len)] = '8';
			*n /= 10;
		}
		*n = -(*n);
	}
}

char	*ft_itoa(int n)
{
	char	*ptr;
	int		len;

	len = ft_nbrlen(n);
	ptr = ft_calloc(len + 1, sizeof(char));
	if (!ptr)
		return (NULL);
	if (n <= 0)
		lesser_num(&n, ptr, &len);
	while (len-- && n != 0)
	{
		ptr[len] = (n % 10) + '0';
		n /= 10;
	}
	return (ptr);
}

// int	main(void)
// {
// 	int		i;
// 	char	*ptr;

// 	i = 0;
// 	ptr = ft_itoa(-2147483648LL);
// 	while (ptr && ptr[i] != '\0')
// 	{
// 		printf("LOOPER: %c\n", ptr[i]);
// 		i++;
// 	}
// 	return (0);
// }
