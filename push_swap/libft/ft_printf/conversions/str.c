/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 07:43:08 by doduwole          #+#    #+#             */
/*   Updated: 2023/04/24 23:51:52 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

int	convert_str(va_list *args)
{
	char	*str;

	str = va_arg(*args, char *);
	if (!str)
		str = "(null)";
	return (ft_putstr(str));
}
