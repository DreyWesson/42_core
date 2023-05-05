/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 06:18:26 by doduwole          #+#    #+#             */
/*   Updated: 2023/05/05 19:57:54 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

int	read_operations(t_node **a, t_node **b, char *ops)
{
	if (!ft_strncmp(ops, "sa\n", 3))
		swap_nodes(*a, (*a)->next, "sa", 0);
	else if (!ft_strncmp(ops, "sb\n", 3))
		swap_nodes(*b, (*b)->next, "sb", 0);
	else if (!ft_strncmp(ops, "ss\n", 3))
		double_swap(*a, *b, 0);
	else if (!ft_strncmp(ops, "pa\n", 3))
		push(b, a, "pa", 0);
	else if (!ft_strncmp(ops, "pb\n", 3))
		push(a, b, "pb", 0);
	else if (!ft_strncmp(ops, "ra\n", 3))
		rotate(a, "ra", 0);
	else if (!ft_strncmp(ops, "rb\n", 3))
		rotate(b, "rb", 0);
	else if (!ft_strncmp(ops, "rr\n", 3))
		double_rotate(a, b, 0);
	else if (!ft_strncmp(ops, "rra\n", 4))
		reverse_rotate(a, "rra", 0);
	else if (!ft_strncmp(ops, "rrb\n", 4))
		reverse_rotate(b, "rrb", 0);
	else if (!ft_strncmp(ops, "rrr\n", 4))
		double_reverse(a, b, 0);
	else
		return (0);
	return (1);
}

int	handle_validation(int argc, char **argv, t_node	**a, t_node	**b)
{
	if (argc < 3)
		return (0);
	if (!validator(argc, argv, a))
	{
		free_both(a, b);
		ft_perror("Error\n");
		return (0);
	}
	if (is_sorted(a))
	{
		print_result(a, b);
		free_both(a, b);
		return (0);
	}
	return (1);
}

void	free_all(char *line_ops, t_node **a, t_node **b)
{
	free(line_ops);
	free_both(a, b);
}

int	is_empty(char *line_ops, t_node **a, t_node **b)
{
	if ((!ft_strncmp(line_ops, "pb\n", 3) && lst_size(a) == 0)
		|| (!ft_strncmp(line_ops, "pa\n", 3) && lst_size(b) == 0))
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;
	char	*line_ops;

	a = NULL;
	b = NULL;
	if (!handle_validation(argc, argv, &a, &b))
		return (0);
	line_ops = get_next_line(0);
	while (line_ops)
	{
		if (is_empty(line_ops, &a, &b))
			break ;
		if (!read_operations(&a, &b, line_ops))
		{
			free_all(line_ops, &a, &b);
			ft_perror("Error\n");
			return (0);
		}
		free(line_ops);
		line_ops = get_next_line(0);
	}
	print_result(&a, &b);
	free_all(line_ops, &a, &b);
	return (0);
}
