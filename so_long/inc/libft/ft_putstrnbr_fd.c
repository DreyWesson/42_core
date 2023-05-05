/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrnbr_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 16:51:14 by doduwole          #+#    #+#             */
/*   Updated: 2023/04/24 23:45:06 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstrnbr_fd(char *str, int nbr)
{
	ft_putstr_fd(str, 1);
	ft_putnbr_fd(nbr, 1);
	ft_putchar_fd('\n', 1);
}
