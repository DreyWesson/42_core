/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 13:56:29 by doduwole          #+#    #+#             */
/*   Updated: 2023/09/29 13:56:37 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	validator(int argc, char **argv)
{
	if (!(argc == 6 || argc == 5))
		return (ft_error("Too few arguments..."), 1);
	while (*argv++)
	{
		if (*argv && is_digit(*argv))
			return (ft_error("Invalid argument"), 2);
	}
	return (0);
}

int	validate_value(long val, t_args type)
{
	if (val == 0 && type != MEAL_NUM)
		return (ft_error("Invalid value"), 0);
	if (type == PHILO_NUM && val > 200)
		return (ft_error("Too many philosophers"), 0);
	return (val);
}
