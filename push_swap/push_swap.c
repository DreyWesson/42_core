/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 12:36:59 by doduwole          #+#    #+#             */
/*   Updated: 2023/03/21 13:14:37 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// t_list *head;

// void	ft_lstprint(void *ptr)
// {
// 	ft_printf("-> %d\n", (int)ptr);
// 	return ;
// }

// ERROR HANDLING
// [✅] check if str will be a proper number
// [✅] convert args to number
// [✅] take care of duplicates like 0==0000 +1 == 1 == 001 === 0001 // trim
// [] take care of too large integers
// [💀] keep only one of all equal numbers
// [💀] first arg should be on top of the stack
// [💀] smallest num at the top
// [💀] separate instructions by a '\n'


int	main(int argc, char** argv)
{
	int		i;
	int* ptr;
	int pos;

	i = 1;
	pos = 0;
	if (argc < 3)
	{
		ft_perror("Error\n");
		return (0);
	}
	ptr = ft_calloc(sizeof(int), (argc - 1));
	while (i < argc)
	{
		// compare string here
		if (!ft_parser(argv[i], ptr, &pos))
		{
			ft_perror("Error\n");
			return (0);
		};
		i++;
	}
	i = 0;
	while (i < (argc - 1))
	{
		ft_printf("%d ", ptr[i]);
		i++;
	}
	return (0);
}