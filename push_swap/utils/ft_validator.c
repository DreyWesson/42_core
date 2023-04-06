/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validator.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 14:59:59 by doduwole          #+#    #+#             */
/*   Updated: 2023/04/06 14:04:37 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int validator(int argc, char** argv, t_node** head)
{
	int		i;

	i = 0;
	while (++i < argc)
		if (!ft_parser(argv[i], head))
			return (0);
	if (check_duplicates(head))
		return (0);
	return (1);
}
