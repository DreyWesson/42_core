/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 06:18:26 by doduwole          #+#    #+#             */
/*   Updated: 2023/04/28 06:54:29 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

int	read_operations(t_node **a, t_node **b, char *ops)
{
	if (!ft_strncmp(ops, "sa\n", 3))
		swap_nodes(*a, (*a)->next, "sa");
	else if (!ft_strncmp(ops, "sb\n", 3))
		swap_nodes(*b, (*b)->next, "sb");
	else if (!ft_strncmp(ops, "ss\n", 3))
		double_swap(a, (*a)->next, b, (*b)->next);
	else if (!ft_strncmp(ops, "pa\n", 3))
		push(b, a, "pa");
	else if (!ft_strncmp(ops, "pb\n", 3))
		push(a, b, "pb");
	else if (!ft_strncmp(ops, "ra\n", 3))
		rotate(a, "ra");
	else if (!ft_strncmp(ops, "rb\n", 3))
		rotate(b, "rb");
	else if (!ft_strncmp(ops, "rr\n", 3))
		double_rotate(a, b);
	else if (!ft_strncmp(ops, "rra\n", 4))
		reverse_rotate(a, "rra");
	else if (!ft_strncmp(ops, "rrb\n", 4))
		reverse_rotate(b, "rrb");
	else if (!ft_strncmp(ops, "rrr\n", 4))
		double_reverse(a, b);
	else
		return (0);
	return (1);
}

void	print_result(t_node **a, t_node **b)
{
	if (is_sorted(a) && !*b)
		ft_putendl_fd("OK", 1);
	else
		ft_putendl_fd("KO", 1);
}

void	free_both(t_node **a, t_node **b)
{
	free_stack(a);
	free_stack(b);
}

int	handle_validation(int argc, char **argv, t_node	**a, t_node	**b)
{
	if (argc < 3)
		return (0);
	a = (t_node **)malloc(sizeof(t_node *));
	b = (t_node **)malloc(sizeof(t_node *));
	if (!validator(argc, argv, a))
	{
		free_both(a, b);
		ft_perror("Error\n");
		return (0);
	}
}

int	main(int argc, char **argv)
{
	t_node	**a;
	t_node	**b;
	char	*ops;

	if (!handle_validation(argc, argv, a, b))
		return (0);
	ops = get_next_line(0);
	while (ops)
	{
		if (!read_operations(&a, &b, ops))
		{
			free(ops);
			free_stack(a);
			ft_perror("Error\n");
		}
		free(ops);
		ops = get_next_line(0);
	}
	free(ops);
	print_result(a, b);
	free_both(a, b);
	return (0);
}