/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioduwole <ioduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 15:11:35 by ioduwole          #+#    #+#             */
/*   Updated: 2022/11/21 15:15:34 by ioduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_c(va_list args);
int	ft_print_s(va_list args);
int	ft_print_i(va_list args);
int	ft_print_d(va_list args);
int	ft_print_u(va_list args);
int	ft_print_x(va_list args, char c);
int	ft_print_p(va_list args);

int	checks(va_list args, const char *format, int i, int len)
{
	i++;
	if (format[i] == 'c')
		len += ft_print_c(args) - 2;
	else if (format[i] == 's')
		len += ft_print_s(args) - 2;
	else if (format[i] == 'i' || format[i] == 'd')
		len += ft_print_i(args) - 2;
	else if (format[i] == 'u')
		len += ft_print_u(args) - 2;
	else if (format[i] == 'x' || format[i] == 'X')
		len += ft_print_x(args, format[i]) - 2;
	else if (format[i] == 'p')
		len += ft_print_p (args);
	else if (format[i] == '%')
		len += write(1, "%", 1) - 2;
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		len;

	va_start (args, format);
	i = 0;
	len = ft_strlen(format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			len = checks(args, format, i, len);
			i++;
		}
		else
			write (1, &format[i], 1);
		i++;
	}
	va_end (args);
	return (len);
}
