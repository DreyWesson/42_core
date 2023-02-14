/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 11:39:50 by doduwole          #+#    #+#             */
/*   Updated: 2023/01/18 15:59:47 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*result;
	t_list	*current_node;

	if (!f || !del)
		return (NULL);
	result = NULL;
	while (lst)
	{
		current_node = ft_lstnew((*f)(lst->content));
		if (!current_node)
		{
			ft_lstclear(&result, del);
			return (NULL);
		}
		ft_lstadd_back(&result, current_node);
		lst = lst->next;
	}
	return (result);
}
// void	del(void *ptr)
// {
// 	printf("DEL-CALLED %p\n", &ptr);
// 	return ;
// }

// void	f(void *ptr)
// {
// 	printf("F-CALLED %p\n", &ptr);
// 	return ;
// }

// int	main(void)
// {
// 	int	ptr;

// 	ptr = 42;
// 	ft_lstdelone(ft_lstnew(&ptr), f);
// 	return (0);
// }
