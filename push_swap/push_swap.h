/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 16:49:58 by doduwole          #+#    #+#             */
/*   Updated: 2023/03/23 11:33:33 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct s_node {
	int value;
	struct s_node* next;
	struct s_node* prev;
}	t_node;


int	ft_parser(char* str, t_node** head_ref);
long	ft_atoi_lg(const char* str);
/**
 * LINKEDLIST OPERATIONS
*/
void ft_print_nodes(t_node** head_ref);
t_node* del_node(t_node** prev_node, t_node* del);
void	add_node_tail(t_node** lst, t_node* new_node);
t_node* create_list(int value);
t_node* ft_last_node(t_node* head_ref);
t_node* del_duplicate_nodes(t_node** head_ref);
void	add_node_head(t_node** head_ref, t_node* new_node);
/**
 * OPERATIONS
*/
void	swap_nodes(t_node* a, t_node* b);
void	double_swap(t_node* a, t_node* b, t_node* x, t_node* y);
void push(t_node** src, t_node** dest);

#endif