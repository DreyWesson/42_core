/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 12:48:23 by doduwole          #+#    #+#             */
/*   Updated: 2023/03/21 18:16:20 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// int	ft_parser(char* str, int* ptr, int* pos)
// {
// 	int	i;

// 	i = 0;
// 	if (ft_strchr("+-", str[i]))
// 		i++;
// 	while (str[i])
// 	{
// 		if (!ft_isdigit(str[i]))
// 			return (0);
// 		i++;
// 	}
// 	ptr[*pos] = ft_atoi(str);
// 	*pos += 1;
// 	return (1);
// }

int	ft_parser(char* str, t_list* head)
{
	int	i;
	int	nbr;

	i = 0;

	if (ft_strchr("+-", str[i]))
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	nbr = ft_atoi(str);
	ft_lstadd_back(&head, ft_lstnew(&nbr));
	return (1);
}
