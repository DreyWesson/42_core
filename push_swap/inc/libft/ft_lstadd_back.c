/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 13:04:34 by doduwole          #+#    #+#             */
/*   Updated: 2023/01/16 14:07:00 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last_node;

	if (*lst)
	{
		last_node = ft_lstlast(*lst);
		last_node->next = new;
	}
	else
		*lst = new;
}
// int	main(void)
// {
// 	t_list	*head;
// 	int 	ptr = 45;
// 	int		ptr2 = 42;

// 	head = ft_lstnew(&ptr);
// 	ft_lstadd_back(&head, ft_lstnew(&ptr2));
// 	printf("%i, %i\n", *(int*)head->content, *(int*)head->next->content);
// 	free(head->next);
// 	free(head);
// 	return (0);
// }
