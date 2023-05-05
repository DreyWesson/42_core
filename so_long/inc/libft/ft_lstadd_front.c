/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 08:21:25 by doduwole          #+#    #+#             */
/*   Updated: 2023/01/16 13:24:37 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!new || !lst)
		return ;
	new->next = *lst;
	*lst = new;
}
// int	main(void)
// {
// 	t_list	*head;
// 	int 	ptr = 45;
// 	int		ptr2 = 42;

// 	head = ft_lstnew(&ptr);
// 	ft_lstadd_front(&head, ft_lstnew(&ptr2));
// 	printf("%i, %i\n", *(int*)head->content, *(int*)head->next->content);
// 	free(head->next);
// 	free(head);
// 	return (0);
// }
