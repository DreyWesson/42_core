/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validator.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 14:59:59 by doduwole          #+#    #+#             */
/*   Updated: 2023/03/23 22:04:32 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int validator(int argc, char** argv, t_node** head, int* size)
{
	int		i;

	i = 0;
	while (++i < argc)
		if (!ft_parser(argv[i], head))
			return (0);
	if (!del_duplicate_nodes(head)->next->next)
		return (0);
	(void)size;
	// if (is_sorted(head, size))
	// 	return (0);
	return (1);
}
