/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 06:23:34 by doduwole          #+#    #+#             */
/*   Updated: 2023/03/02 12:17:19 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static t_server	g_server;

/* Launching of the server and variables initialization */
void	ft_init(void)
{
	pid_t	pid;

	g_server.bit = 8;
	g_server.c = 0;
	pid = getpid();
	printf("Server PID -> %u\n", pid);
	printf("Data sent from server -> \n");
}

/* Handle and decode the SIGUSR2 signals */
void	ft_handler0(int signal)
{
	(void)signal;
	g_server.bit--;
	g_server.c += (0 << g_server.bit);
	if (g_server.bit == 0)
	{
		ft_putchar_fd(g_server.c, 1);
		g_server.bit = 8;
		g_server.c = 0;
	}
}

/* Handle and decode the SIGUSR2 signals */
void	ft_handler1(int signal)
{
	(void)signal;
	g_server.bit--;
	g_server.c += (1 << g_server.bit);
	if (g_server.bit == 0)
	{
		ft_putchar_fd(g_server.c, 1);
		g_server.bit = 8;
		g_server.c = 0;
	}
}

int	main(void)
{
	ft_init();
	while (1)
	{
		signal(SIGUSR1, ft_handler0);
		signal(SIGUSR2, ft_handler1);
		pause();
	}
	return (0);
}
