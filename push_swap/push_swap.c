/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 12:36:59 by doduwole          #+#    #+#             */
/*   Updated: 2023/03/21 18:18:35 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


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

// int	main(int argc, char** argv)
// {
// 	int		i;
// 	int* ptr;
// 	int pos;
// 	i = 1;
// 	pos = 0;
// 	if (argc < 3)
// 	{
// 		ft_perror("Error\n");
// 		return (0);
// 	}
// 	ptr = ft_calloc(sizeof(int), (argc - 1));
// 	while (i < argc)
// 	{
// 		if (!ft_parser(argv[i], ptr, &pos))
// 		{
// 			ft_perror("Error\n");
// 			return (0);
// 		};
// 		i++;
// 	}
// 	i = 0;
// 	while (i < (argc - 1))
// 	{
// 		ft_printf("%d ", ptr[i]);
// 		i++;
// 	}
// 	return (0);
// }


int	main(int argc, char** argv)
{
	int		i;
	t_list* head;
	int* ptr;

	i = 1;
	if (argc < 3)
	{
		ft_perror("Error\n");
		return (0);
	}
	head = (t_list*)ft_calloc(sizeof(t_list*), (argc - 2));
	while (i < argc)
	{
		if (!ft_parser(argv[i], head))
		{
			ft_perror("Error\n");
			return (0);
		}
		i++;
	}
	ptr = head->next->content;
	ft_printf("%d\n", *ptr);
	return (0);
}
