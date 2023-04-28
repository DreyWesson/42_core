/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 12:47:02 by doduwole          #+#    #+#             */
/*   Updated: 2023/01/18 15:52:20 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;

	if (!del || !lst || !*lst)
		return ;
	while (lst && *lst)
	{
		tmp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = tmp;
	}
}
// void	del(void *ptr)
// {
// 	printf("HERE %p\n", &ptr);
// 	return ;
// }

// int	main(void)
// {
// 	int	ptr;

// 	ptr = 42;
// 	ft_lstclear((t_list **)ft_lstnew(&ptr), del);
// 	return (0);
// }
