/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 15:48:40 by doduwole          #+#    #+#             */
/*   Updated: 2023/01/18 15:58:01 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst)
		return ;
	while (lst)
	{
		(*f)(lst->content);
		lst = lst->next;
	}
}
// void	f(void *ptr)
// {
// 	printf("HERE %i\n", (int)ptr);
// 	return ;
// }

// int	main(void)
// {
// 	int	ptr;

// 	ptr = 42;
// 	ft_lstiter(ft_lstnew(&ptr), f);
// 	return (0);
// }
