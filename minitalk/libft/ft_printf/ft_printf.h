/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 10:47:34 by doduwole          #+#    #+#             */
/*   Updated: 2023/03/19 03:01:00 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
/*
** CONVERSION FUNCTIONS
*/
int		convert_char(va_list *args);
int		convert_str(va_list *args);
int		convert_int(va_list *args);
int		convert_ptr(va_list *args, char val);
int		convert_xes(va_list *args, char val);
int		convert_u(va_list *args);
int		is_valid_format(const char *format);
/*
** UTIL FUNCTIONS
*/
int		ft_converter(char val, va_list *args);
int		str_validator(const char *format);
/*
** UTIL FUNCTIONS
*/
int		ft_converter(char val, va_list *args);
int		str_validator(const char *format);

#endif