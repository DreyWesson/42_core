/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 12:40:17 by doduwole          #+#    #+#             */
/*   Updated: 2023/01/16 13:21:00 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst)
	{
		if (!lst->next)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}
// int	main(void)
// {
// 	t_list	*head;
// 	int 	ptr = 45;
// 	int		ptr2 = 42;
// 	int		ptr3 = 49;

// 	head = ft_lstnew(&ptr);
// 	ft_lstadd_front(&head, ft_lstnew(&ptr2));
// 	ft_lstadd_front(&head, ft_lstnew(&ptr3));
// 	printf("%i\n", *(int *)ft_lstlast(head)->content);
// 	free(head->next);
// 	free(head);
// 	return (0);
// }
