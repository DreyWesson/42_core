/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_perror.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 05:44:59 by doduwole          #+#    #+#             */
/*   Updated: 2023/04/26 10:06:34 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_char_err(int c)
{
	return (write(2, &c, 1));
}

int	ft_perror(char *str)
{
	int	ret;
	int	i;

	ret = 0;
	i = -1;
	while (str[++i])
		ret += ft_char_err(str[i]);
	return (ret);
}
