/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 15:28:47 by doduwole          #+#    #+#             */
/*   Updated: 2023/04/24 23:44:56 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr(char *str)
{
	int	ret;
	int	i;

	ret = 0;
	i = -1;
	while (str[++i])
		ret += ft_putchar(str[i]);
	return (ret);
}
