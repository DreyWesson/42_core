/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five_max.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 18:56:40 by doduwole          #+#    #+#             */
/*   Updated: 2023/04/24 12:20:00 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int target_pos(t_node** stack_a, int target_value)
{
	t_node* tmp;
	int size;

	size = 0;
	tmp = *stack_a;
	while (tmp->next)
	{
		size++;
		if (target_value == tmp->value)
			break;
		tmp = tmp->next;
	}
	return (size);
}

void move_picker(t_node** stack, int target_pos, int mid_pos)
{
	int size;

	size = lst_size(stack);
	if (target_pos <= mid_pos)
		repeat_rotate(stack, target_pos, "ra");
	else if (target_pos > mid_pos)
		repeat_reverse(stack, size - target_pos, "rra");
}

void re_sort(t_node** stack_a)
{
	t_node_details* min;
	t_node_details* mid;

	min = min_node_details(stack_a);
	mid = mid_node_details(stack_a);
	move_picker(stack_a, min->pos, mid->pos);
}

void re_calibrator(t_node** head_ref)
{
	t_node* tmp;
	int i;

	if (!head_ref)
		return;
	i = 0;
	tmp = *head_ref;
	while (tmp)
	{
		tmp->list_idx = i;
		tmp = tmp->next;
		i++;
	}
}

void reconfigure(t_node** stack_a, t_node** stack_b)
{
	re_calibrator(stack_b);
	re_calibrator(stack_a);
	exit_cost(stack_b);
	target_cost(stack_a, stack_b);
	optimize(stack_b);
	priority(stack_b);
}

t_node* highest_priority(t_node** stack_b)
{
	int nbr;
	t_node* tmp;
	t_node* highest;

	nbr = 2147483647;
	tmp = *stack_b;

	while (tmp)
	{
		if (tmp->priority < nbr)
		{
			highest = tmp;
			nbr = tmp->priority;
		}
		if (tmp->priority == nbr && tmp->optimized > 0)
		{
			highest = tmp;
			nbr = tmp->priority;
		}
		tmp = tmp->next;
	}
	return (highest);
}

void sort_more(t_node** stack_a, t_node** stack_b)
{
	t_node* highest;
	handle_indexing(stack_a);

	// ✅ check num of values in position
		// ✅ if more than three then dont push those
		// ✅ else push all until 3
	// ✅ calc exit cost of each from stack_b
	// ✅ calc target cost of each
	// ✅ check total cost of each by comparing the exit and target cost
	// ✅ check opportunity to perform double ops if eit and target share same sign

	// 🔴 after every push check if list is sorted cyclically or default sorted	 AND reconfigure properties


	push_unsorted_only(stack_a, stack_b, "pb");
	// if (lst_size(stack_a) == 3 && (!is_sorted(stack_a) && !is_cyclic(stack_a)))
	// 	sort_three_max(stack_a, 'y');
	int num;

	while (*stack_b)
	{
		reconfigure(stack_a, stack_b);
		highest = highest_priority(stack_b);
		if (highest->optimized != 0)
		{
			if (highest->optimized > 0)
			{
				num = highest->optimized;
				repeat_double_rotate(stack_a, stack_b, num);
				highest->exit_cost -= num;
				highest->target_cost -= num;
			}
			else
			{
				num = highest->optimized;
				repeat_double_reverse(stack_a, stack_b, num);
				highest->exit_cost -= (num * -1);
				highest->target_cost -= (num * -1);
				// if ((*stack_a)->exit_cost < (*stack_a)->target_cost)
				// 	repeat_reverse(stack_b, (*stack_b)->exit_cost + (num * -1), "rrb");
				// else
				// 	repeat_reverse(stack_a, (*stack_b)->target_cost - num, "rra");
				// push(stack_b, stack_a, "pa");
			}
		}

		if (highest->exit_cost >= 0)
			repeat_rotate(stack_b, highest->exit_cost, "rb");
		else if (highest->exit_cost < 0)
			repeat_reverse(stack_b, highest->exit_cost, "rrb");

		if (highest->target_cost >= 0)
			repeat_rotate(stack_a, highest->target_cost, "ra");
		else if (highest->target_cost < 0)
			repeat_reverse(stack_a, highest->target_cost, "rra");
		push(stack_b, stack_a, "pa");
		if (!is_sorted(stack_a) && !is_cyclic(stack_a))
		{
			printf("Something is wrong with sorting\n");
			break;
		}
	}


	ft_print_nodes(stack_a, ' ');

	if (is_sorted(stack_a))
		return;
	re_sort(stack_a);
	ft_print_nodes(stack_a, ' ');

}

// printf("pos: %d, min_pos: %d\n", pos, min->pos);
// printf("==fwd==>size: %d, target: %d\n", target_pos(stack_a, tmp->value), tmp->value);
// printf("==rwd==>size: %d, target: %d\n", target_pos(stack_a, tmp->value), tmp->value);
// printf("=======> a-top: %d, b-top: %d, max_val: %d, min_val: %d tail: %d, target_pos: %d\n", (*stack_a)->value, (*stack_b)->value, max->value, min->value, ft_last_node(*stack_a)->value, target_pos(stack_a, min->value) - 1);