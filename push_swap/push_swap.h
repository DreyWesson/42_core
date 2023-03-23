/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 16:49:58 by doduwole          #+#    #+#             */
/*   Updated: 2023/03/23 22:02:22 by doduwole         ###   ########.fr       */
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

typedef struct s_sorted {
	int stack_size;
	int is_sorted;
} t_sorted;

int	ft_parser(char* str, t_node** head_ref);
long	ft_atoi_lg(const char* str);
int validator(int argc, char** argv, t_node** head, int* size);
int is_sorted(t_node** head_ref, int* size);
void dummystack(t_node** stack);
/**
 * LINKEDLIST
*/
void ft_print_nodes(t_node** head_ref);
t_node* del_node(t_node** prev_node, t_node* target_node);
void	add_node_tail(t_node** lst, t_node* new_node);
t_node* create_node(int value);
t_node* ft_last_node(t_node* head_ref);
t_node* del_duplicate_nodes(t_node** head_ref);
void	add_node_head(t_node** head_ref, t_node* new_node);
void free_stack(t_node** stack);
/**
 * OPERATIONS
*/
void	swap_nodes(t_node* a, t_node* b);
void	double_swap(t_node* a, t_node* b, t_node* x, t_node* y);
void push(t_node** src, t_node** dest);
void rotate(t_node** head_ref);
void double_rotate(t_node** a, t_node** b);
void reverse_rotate(t_node** head_ref);
void double_reverse(t_node** a, t_node** b);

#endif