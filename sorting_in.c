/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_in.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 12:36:59 by doduwole          #+#    #+#             */
/*   Updated: 2023/03/20 16:10:10 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct s_list {
	int value;
	struct s_list* next;
}	t_list;

t_list* head;
int MAX = 0;

void print_list(t_list* head) {
	if (!head)
		return;
	while (head)
	{
		printf("%d\n", head->value);
		head = head->next;
	}
}

t_list* create_node(int value) {
	t_list* node;

	node = malloc(sizeof(t_list));
	node->value = value;
	node->next = NULL;
	MAX++;
	return (node);
}

t_list* transverse(t_list* head, int idx)
{
	t_list* target_node;
	int i = 0;

	target_node = head;
	while (target_node->next)
	{
		if (i == idx - 1)
			break;
		target_node = target_node->next;
		i++;
	}
	return (target_node);
}

t_list* insert_node(t_list* head, int idx, t_list* new_node)
{
	t_list* target_node;
	t_list* rest_node;

	target_node = transverse(head, idx - 1);
	rest_node = target_node->next;
	new_node->next = rest_node;
	target_node->next = new_node;
	MAX++;
	return (head);
}

t_list* delete_node(t_list* head, int idx)
{
	t_list* target_node;
	t_list* rest_node;

	if (idx == 0)
	{
		head = head->next;
	}
	else {
		target_node = transverse(head, idx - 1);
		rest_node = target_node->next->next;
		target_node->next = rest_node;
	}



	MAX--;
	return (head);
}

t_list* add_node_tail(t_list* head, t_list* new_node)
{
	new_node->next = head;
	head = new_node;
	return (head);
}

t_list* add_node_head(t_list* head, t_list* new_node)
{
	t_list* last_node;

	last_node = transverse(head, MAX);
	last_node->next = new_node;
	return (head);
}

t_list* bubble_sort(t_list* head)
{
	t_list* current_node;
	t_list* iterator_node;
	int tmp_val;

	current_node = head;
	while (current_node)
	{
		iterator_node = head;
		while (iterator_node)
		{
			if (iterator_node->next && iterator_node->value > iterator_node->next->value)
			{
				tmp_val = iterator_node->value;
				iterator_node->value = iterator_node->next->value;
				iterator_node->next->value = tmp_val;
			}
			iterator_node = iterator_node->next;
		}
		current_node = current_node->next;
	}
	return (head);
}

t_list* insertion_sort(t_list* head)
{
	t_list	*current_node;
	t_list	*iterator_node;
	int		tmp_val;

	current_node = head;
	while (current_node)
	{
		iterator_node = head;
		while (iterator_node)
		{
			iterator_node = 
			iterator_node = iterator_node->next;
		}
		current_node = current_node->next;
	}
	return (head);
}

int	main(void)
{
	int	i;

	i = 6;
	int arr[6] = { 12, 11, 5, -13, 6, 4 };
	//  11   5 -13   6    4   12
	//   5 -13   6   4   11   12
	// -13   5   6   4   11   12
	// -13   4   5   6   11   12
	while (--i >= 0)
		head = add_node_tail(head, create_node(arr[i]));
	// print_list(head);
	// add_node_head(head, create_node(5));
	// print_list(insert_node(head, 3, create_node(3)));
	// bubble_sort(head);
	insertion_sort(head);
	print_list(head);
	return (0);
}
