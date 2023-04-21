/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_in.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 12:36:59 by doduwole          #+#    #+#             */
/*   Updated: 2023/04/21 10:35:47 by doduwole         ###   ########.fr       */
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
	t_list* current_node;
	t_list* iterator_node;
	// int		tmp_val;

	current_node = head;
	while (current_node)
	{
		iterator_node = head;
		while (iterator_node)
		{
			iterator_node = iterator_node->next;
		}
		current_node = current_node->next;
	}
	return (head);
}

void sort(t_list* head)
{
	t_list* tmp;
	t_list* tmp2;
	int cache;

	tmp = head;
	tmp2 = head;
	while (tmp)
	{
		tmp2 = head;
		while (tmp2)
		{
			if (tmp->value < tmp2->value)
			{
				cache = tmp->value;
				tmp->value = tmp2->value;
				tmp2->value = cache;
			}
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
}

int	main(void)
{
	int	i;

	i = 100;
	int arr[100] = { 125, 75, 104, 81, 103, 110, 121, 8, 63, 19, 86, 89, 77, 85, 70, 115, 101, 114, 67, 147, 6, 119, 21, 93, 118, 83, 1, 98, 27, 99, 26, 32, 97, 96, 36, 122, 153, 23, 111, 66, 152, 150, 16, 34, 112, 108, 141, 51, 157, 40, 143, 155, 14, 116, 69, 33, 120, 144, 159, 133, 30, 31, 0, 140, 48, 43, 59, 82, 38, 88, 20, 24, 18, 17, 139, 117, 35, 151, 45, 145, 22, 47, 65, 92, 138, 156, 50, 25, 135, 80, 41, 130, 11, 95, 37, 158, 126, 106, 12, 76 };
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
	// insertion_sort(head);
	sort(head);
	print_list(head);
	return (0);
}
