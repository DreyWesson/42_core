/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 09:07:13 by doduwole          #+#    #+#             */
/*   Updated: 2023/05/29 08:09:14 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	ft_error(char *message)
{
	ft_printf("\033[1;31m" "Error\n" "\033[0m");
	ft_printf("\033[3m\033[2;37m" " %s\n" "\033[0m", message);
	return (0);
}

void	ft_warning(char *message)
{
	ft_printf("\033[1;33m" "Warning\n" "\033[0m");
	ft_printf("\033[3m\033[2;37m" " %s\n" "\033[0m", message);
}

// void	*null_error(char *message)
// {
// 	ft_printf("\033[0;31m" " Error\n %s\n" "\033[0m", message);
// 	return (0);
// }
