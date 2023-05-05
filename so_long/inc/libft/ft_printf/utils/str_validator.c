/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 19:20:43 by doduwole          #+#    #+#             */
/*   Updated: 2023/04/24 23:53:03 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

int	str_validator(const char *format)
{
	int		i;
	char	*str;

	if (!format[0])
		return ('\0');
	i = 0;
	str = "csidpuxX%";
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '\0' || !ft_strchr(str, format[i]))
				return ('\0');
		}
		i++;
	}
	return (1);
}
