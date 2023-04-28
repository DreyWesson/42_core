/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 12:29:42 by doduwole          #+#    #+#             */
/*   Updated: 2023/01/18 15:57:43 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	size_t	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
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
// 	// printf("%i, %i\n", *(int*)head->content, *(int*)head->next->content);
// 	printf("%i\n", ft_lstsize(head));
// 	free(head->next);
// 	free(head);
// 	return (0);
// }
