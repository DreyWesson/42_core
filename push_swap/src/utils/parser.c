/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 12:48:23 by doduwole          #+#    #+#             */
/*   Updated: 2023/04/28 06:58:49 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

int	ft_parser(char *str, t_node **head_ref, int idx)
{
	int		i;
	long	nbr;

	i = 0;
	if (ft_strchr("+-", str[i]))
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	nbr = ft_atoi_lg(str);
	if (nbr < -2147483648 || nbr > 2147483647)
		return (0);
	add_node_tail(head_ref, create_node(nbr, idx));
	return (1);
}
