/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 16:49:58 by doduwole          #+#    #+#             */
/*   Updated: 2023/03/23 00:17:46 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct s_node {
	int content;
	struct s_node* next;
	struct s_node* prev;
}	t_node;


int	ft_parser(char* str, t_node** head);
long	ft_atoi_lg(const char* str);
void ft_print_nodes(t_node** head);
t_node* del_node(t_node** prev_node, t_node* del);
void	swap_nodes(t_node* a, t_node* b);
void	add_node_tail(t_node** lst, t_node* new);
t_node* create_list(int content);
t_node* ft_last_node(t_node* lst);
t_node* del_duplicate_nodes(t_node* head);
void push(t_node* src, t_node* dest);
void	add_node_head(t_node** lst, t_node* new);

#endif