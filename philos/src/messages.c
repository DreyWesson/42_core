/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 19:23:32 by doduwole          #+#    #+#             */
/*   Updated: 2023/09/23 12:10:33 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	print_state(t_philo *phi, int id, char *color, char *status)
{
	long long	now;

	now = time_diff(phi->data->timer);
	pthread_mutex_lock(&phi->data->print);
	pthread_mutex_lock(&phi->data->shared);
	if (phi->data->philo_died)
	{
		pthread_mutex_unlock(&phi->data->shared);
		pthread_mutex_unlock(&phi->data->print);
		return (0);
	}
	else
		printf("%s%-10lld %-3d %-30s%s\n", color, now, id, status, NONE);
	pthread_mutex_unlock(&phi->data->shared);
	pthread_mutex_unlock(&phi->data->print);
	return (1);
}
