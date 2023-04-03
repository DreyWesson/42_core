/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 23:42:08 by doduwole          #+#    #+#             */
/*   Updated: 2023/04/03 23:15:26 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_three_max(t_node** head_ref)
{
	int mid_pos;
	int max_pos;
	int min_pos;
	int** ptr;

	if (is_sorted(head_ref))
		return;
	if (lst_size(head_ref) == 2)
		return (swap_nodes(*head_ref, (*head_ref)->next, "sa"));
	ptr = find_min_max(head_ref);

	min_pos = ptr[0][0];
	mid_pos = ptr[1][0];
	max_pos = ptr[2][0];
	if (max_pos < mid_pos)
		rotate(head_ref, "ra");
	else if (max_pos > mid_pos)
		swap_nodes(*head_ref, (*head_ref)->next, "sa");
	else if ((min_pos < mid_pos || min_pos > mid_pos))
		reverse_rotate(head_ref, "rra");
	free(ptr);
	sort_three_max(head_ref);
}
int check_quarters(t_node* stack_b, int** ptr, int type)
{
	while (stack_b)
	{
		if ((stack_b)->value > ptr[0][1] && (stack_b)->value < ptr[1][1])
			type++;
		else if ((stack_b)->value > ptr[1][1] && (stack_b)->value < ptr[2][1])
			type += 2;
		else if ((stack_b)->value > ptr[2][1])
			type += 3;
		stack_b = (stack_b)->next;
	}
	return (type);
}

void repeat_push(t_node** x, t_node** y, int num, char* ptr)
{
	int i;

	i = -1;
	while (++i < num)
		push(x, y, ptr);
}
void repeat_rotate(t_node** x, int num, char* ptr)
{
	int i;

	i = -1;
	while (++i < num)
		rotate(x, ptr);
}
void repeat_reverse(t_node** x, int num, char* ptr)
{
	int i;

	i = -1;
	while (++i < num)
		reverse_rotate(x, ptr);
}

void type_0(t_node** stack_a, t_node** stack_b) {
	if (is_sorted(stack_b))
		rotate(stack_b, "ra");
	repeat_push(stack_b, stack_a, 2, "pa");
}
void type_2(t_node** stack_a, t_node** stack_b) {
	if (is_sorted(stack_b))
		rotate(stack_b, "rb");
	rotate(stack_a, "ra");

	repeat_push(stack_b, stack_a, 2, "pa");
	reverse_rotate(stack_a, "ra");
}
void type_3(t_node** stack_a, t_node** stack_b) {
	if (!is_sorted(stack_b))
		rotate(stack_b, "rb");
	rotate(stack_a, "pa");
	push(stack_b, stack_a, "pa");
	repeat_rotate(stack_a, 2, "ra");
	push(stack_b, stack_a, "pa");
	repeat_rotate(stack_a, 2, "ra");
}
void type_4(t_node** stack_a, t_node** stack_b) {
	if (is_sorted(stack_b))
		rotate(stack_b, "rb");
	reverse_rotate(stack_a, "pa");
	repeat_push(stack_b, stack_a, 2, "pa");
	repeat_reverse(stack_a, 2, "ra");

}
void type_6(t_node** stack_a, t_node** stack_b) {
	if (is_sorted(stack_b))
		rotate(stack_a, "ra");
	repeat_push(stack_b, stack_a, 2, "pa");
	repeat_rotate(stack_a, 2, "ra");
}
void sort_more(t_node** stack_a, t_node** stack_b)
{
	int** ptr;
	int type;

	type = 0;
	repeat_push(stack_a, stack_b, 2, "pb");
	sort_three_max(stack_a);
	ptr = find_min_max(stack_a);
	type = check_quarters(*stack_b, ptr, type);
	if (type == 0)
		type_0(stack_a, stack_b);
	else if (type == 6)
		type_6(stack_a, stack_b);
	else if (type == 2)
		type_2(stack_a, stack_b);
	else if (type == 4)
		type_4(stack_a, stack_b);
	else
		type_3(stack_a, stack_b);
}
