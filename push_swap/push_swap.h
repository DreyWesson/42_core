/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 16:49:58 by doduwole          #+#    #+#             */
/*   Updated: 2023/04/12 16:04:07 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
#include <stdio.h>

typedef struct s_node {
	int value;
	struct s_node* next;
	struct s_node* prev;
}	t_node;

typedef struct s_node_details {
	int pos;
	int value;
	struct s_node* node;
}	t_node_details;
/**
 * UTILS FUNCTIONS
*/
int		ft_parser(char* str, t_node** head_ref);
long	ft_atoi_lg(const char* str);
int validator(int argc, char** argv, t_node** head);
int is_sorted(t_node** head_ref);
int is_cyclic(t_node** stack_a);
void dummystack(t_node** stack);
// int** find_min_max(t_node** head_ref);
void sort_router(t_node** stack_a, t_node** stack_b);
/**
 * LINKEDLIST
*/
void ft_print_nodes(t_node** head_ref);
t_node* del_node(t_node** prev_node, t_node* target_node);
void	add_node_tail(t_node** lst, t_node* new_node);
t_node* create_node(int value);
t_node* ft_last_node(t_node* head_ref);
int		check_duplicates(t_node** head_ref);
void	add_node_head(t_node** head_ref, t_node* new_node);
void free_stack(t_node** stack);
int lst_size(t_node** head_ref);
void special_nodes(t_node** stack_a, t_node_details** min_details,
	t_node_details** max_details, t_node_details** mid_details);
t_node_details* max_node_details(t_node** head_ref);
t_node_details* min_node_details(t_node** head_ref);
t_node_details* mid_node_details(t_node** head_ref);
/**
 * OPERATIONS
*/
void	swap_nodes(t_node* a, t_node* b, char* tag);
void	double_swap(t_node* a, t_node* b, t_node* x, t_node* y);
void push(t_node** src, t_node** dest, char* tag);
void rotate(t_node** head_ref, char* tag);
void double_rotate(t_node** a, t_node** b);
void reverse_rotate(t_node** head_ref, char* tag);
void double_reverse(t_node** a, t_node** b);
/**
 * REPEATERS
*/
void repeat_push(t_node** x, t_node** y, int num, char* ptr);
void repeat_rotate(t_node** x, int num, char* ptr);
void repeat_reverse(t_node** x, int num, char* ptr);
int	push_unsorted_only(t_node** x, t_node** y, int num, char* ptr);
/**
 * SORT FUNCTIONS
*/
void sort_three_max(t_node** head_ref, char check_cyclic);
void sort_more(t_node** stack_a, t_node** stack_b, int leftover);

#endif