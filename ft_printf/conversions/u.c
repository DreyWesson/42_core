/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 14:00:49 by doduwole          #+#    #+#             */
/*   Updated: 2023/02/03 08:26:54 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	convert_u(va_list* args)
{
	unsigned int	ptr;
	int				ret;
	char* c;

	ret = 0;
	ptr = va_arg(*args, unsigned int);
	if (ptr == 0)
		return (ft_putchar('0'));
	c = ft_utoa(ptr);
	ret += ft_putstr(c);
	free(c);
	return (ret);
}
