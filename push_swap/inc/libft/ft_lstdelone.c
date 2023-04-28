/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:35:45 by doduwole          #+#    #+#             */
/*   Updated: 2023/01/18 15:28:43 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst)
		return ;
	(*del)(lst->content);
	free(lst);
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
// 	ft_lstdelone(ft_lstnew(&ptr), del);
// 	return (0);
// }
