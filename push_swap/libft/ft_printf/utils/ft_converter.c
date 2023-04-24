/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_converter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 19:18:41 by doduwole          #+#    #+#             */
/*   Updated: 2023/04/24 23:52:45 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

int	ft_converter(char val, va_list *args)
{
	int		i;

	i = 0;
	if (val == 'c')
		i = convert_char(args);
	else if (val == 's')
		i = convert_str(args);
	else if (val == 'i' || val == 'd')
		i = convert_int(args);
	else if (val == 'p')
		i = convert_ptr(args, val);
	else if (val == 'x' || val == 'X')
		i = convert_xes(args, val);
	else if (val == 'u')
		i = convert_u(args);
	else if (val == '%')
		i = ft_putchar(val);
	return (i);
}
