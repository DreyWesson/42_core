/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sign_based_logic.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 00:26:59 by doduwole          #+#    #+#             */
/*   Updated: 2023/04/25 00:34:15 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	both_positive(t_node *tmp)
{
	if (tmp->exit_cost >= tmp->target_cost)
		tmp->priority = tmp->exit_cost;
	else if (tmp->target_cost > tmp->exit_cost)
		tmp->priority = tmp->target_cost;
}

void	both_negative(t_node *tmp)
{
	if (tmp->exit_cost <= tmp->target_cost)
		tmp->priority = tmp->exit_cost * -1;
	else if (tmp->exit_cost > tmp->target_cost)
		tmp->priority = tmp->target_cost * -1;
}

void	exit_zero(t_node *tmp)
{
	if (tmp->target_cost >= 0)
		tmp->priority = tmp->target_cost;
	else
		tmp->priority = tmp->target_cost * -1;
}

void	target_zero(t_node *tmp)
{
	if (tmp->exit_cost >= 0)
		tmp->priority = tmp->exit_cost;
	else
		tmp->priority = tmp->exit_cost * -1;
}