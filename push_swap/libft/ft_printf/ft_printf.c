/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 10:46:18 by doduwole          #+#    #+#             */
/*   Updated: 2023/04/24 23:53:11 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_printf(const char *format, ...)
{
	int		i;
	int		ret;
	va_list	args;

	if (!str_validator(format))
		return ('\0');
	i = 0;
	ret = 0;
	va_start(args, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			ret += ft_converter(format[i], &args);
		}
		else
			ret += ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (ret);
}

// int	main(void)
// {
// 	ft_printf("%X", -10);
// 	return (0);
// }
// 	// int i;
// 	// i = 42;
// 	// ft_printf("%c%c%c", 'a', '\t', 'b');
// 	// printf("1->%d\n", ft_printf("%%\n")); // %p tester
// 	// printf("2->%d\n", printf("%%\n")); // %p tester
// 	// ft_printf("%s", (char*)NULL);
// 	// printf("my len = %d\n", ft_printf("%s %s\n", "Hello", "world"));
// 	ft_printf(" %u \n", 0);
// 	// ft_printf(" %p %p \n", 0, 0);
// printf("->%d %p\n", ft_printf("%p\n", &i), &i); // %p tester
// printf("%d\n",ft_printf("hello %s\n","world")); //%s tester
// printf("->%d\n", ft_printf("hello %d\n", 23456)); // %d/%i tester
