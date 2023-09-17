/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 19:37:24 by doduwole          #+#    #+#             */
/*   Updated: 2023/09/06 16:50:30 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/philosopher.h"

void	*routine(void *arg)
{
	printf("Hello philosopher\n");
	sleep(3);
	printf("Dead\n");
	(void)arg;
	return (NULL);
}

int	main(int argc, char **argv)
{
	pthread_t t1;
	pthread_t t2;

	(void)argc;
	(void)argv;
	pthread_create(&t1, NULL, &routine, NULL);
	pthread_create(&t2, NULL, &routine, NULL);
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	return (0);
}