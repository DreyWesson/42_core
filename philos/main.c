/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 19:37:24 by doduwole          #+#    #+#             */
/*   Updated: 2023/09/29 09:01:53 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/philo.h"

int	single_philo(t_data *data, t_philo *phi)
{
	data->timer = get_time();
	print_state(phi, 1, NONE, FORK);
	time_sim(data->time.to_die);
	print_state(phi, 1, RED, DIED);
	free_all(data, phi);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	*data;
	t_philo	*philo;

	if (validator(argc, argv))
		return (1);
	data = malloc(sizeof(t_data));
	if (!data)
		return (ft_error("Memory allocation failed"), 2);
	if (!init_data(data, argv, argc))
		return (2);
	if (!mutex_init(data))
		return (3);
	philo = malloc(sizeof(t_philo) * (data->philo_num + 1));
	if (!philo)
		return (ft_error("Memory allocation failed"), 4);
	init_philo(philo, data);
	if (data->philo_num == 1)
		return (single_philo(data, philo));
	if (!handle_thread(philo))
		return (free_all(data, philo), 6);
	return (free_all(data, philo), 0);
}
