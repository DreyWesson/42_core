/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 16:49:58 by doduwole          #+#    #+#             */
/*   Updated: 2023/04/26 10:40:23 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdio.h>

typedef struct s_node {
	int				value;
	int				order_idx;
	int				list_idx;
	int				exit_cost;
	int				target_cost;
	int				optimized;
	int				priority;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_node_details {
	int				pos;
	int				value;
	struct s_node	*node;
}	t_node_details;

typedef struct s_details {
	t_node_details	*min;
	t_node_details	*mid;
	t_node_details	*max;
}	t_details;

/**
 * UTILS FUNCTIONS
*/
int					ft_parser(char *str, t_node **head_ref, int i);
long				ft_atoi_lg(const char *str);
int					validator(int argc, char **argv, t_node **head);
int					is_sorted(t_node **head_ref);
int					is_cyclic(t_node **stack_a);
void				sort_router(t_node **stack_a, t_node **stack_b);
void				handle_indexing(t_node **stack_a);
int					target_pos(t_node **stack_a, int target_value);
void				target_zero(t_node *tmp);
void				exit_zero(t_node *tmp);
void				both_negative(t_node *tmp);
void				both_positive(t_node *tmp);
void				head_to_tail(t_node **stack_a,
						t_node *exiting_node, char *found);
int					spring(t_node **stack_a, t_node *exiting_node,
						char *found, t_details *details);
void				waterfall(t_node **stack_a, t_node *exiting_node,
						char *found, t_details *details);
void				min_max_handler(t_node **stack_a,
						t_node *exiting_node, char *found);
void				move_picker(t_node **stack, int target_pos,
						int mid_pos);
void				helper(t_node *highest, t_node **stack_a,
						t_node **stack_b, char ptr);
/**
 * LINKEDLIST
*/
void				ft_print_nodes(t_node **head_ref, char ptr);
void				add_node_tail(t_node **lst, t_node *new_node);
int					check_duplicates(t_node** head_ref);
void				add_node_head(t_node **head_ref, t_node *new_node);
void				free_stack(t_node **stack);
int					lst_size(t_node **head_ref);
t_node				*create_node(int value, int idx);
t_node				*del_node(t_node **prev_node, t_node *target_node);
t_node				*ft_last_node(t_node *head_ref);
t_details			*special_nodes(t_node **stack_a);
t_node_details		*max_node_details(t_node **head_ref);
t_node_details		*min_node_details(t_node **head_ref);
t_node_details		*mid_node_details(t_node **head_ref);
/**
 * OPERATIONS
*/
void				swap_nodes(t_node *a, t_node *b, char *tag);
void				double_swap(t_node *a, t_node *b, t_node *x, t_node *y);
void				push(t_node **src, t_node **dest, char *tag);
void				rotate(t_node **head_ref, char *tag);
void				reverse_rotate(t_node **head_ref, char *tag);
void				double_rotate(t_node **a, t_node **b);
void				double_reverse(t_node **a, t_node **b);
void				repeat_double_reverse(t_node **x, t_node **y, int num);
void				repeat_double_rotate(t_node **x, t_node **y, int num);
/**
 * REPEATERS
*/
void				repeat_push(t_node **x, t_node **y, int num, char *ptr);
void				repeat_rotate(t_node **x, int num, char *ptr);
void				repeat_reverse(t_node **x, int num, char *ptr);
/**
 * SORT FUNCTIONS
*/
void				sort_three_max(t_node **head_ref, char check_cyclic);
void				sort_more(t_node **stack_a, t_node **stack_b);
int					*bubble_sort(int *ptr, int size);
/**
 * COST FUNCTIONS
*/
void				exit_cost(t_node **stack);
void				target_cost(t_node **stack_a, t_node **stack_b);
void				priority(t_node **stack_b);
void				optimize(t_node **stack_b);
t_node				*highest_priority(t_node **stack_b);
/**
 * RESET FUNCTIONS
*/
void				reconfigure(t_node **stack_a, t_node **stack_b);
void				re_calibrator(t_node **head_ref);
void				re_sort(t_node **stack_a);

#endif