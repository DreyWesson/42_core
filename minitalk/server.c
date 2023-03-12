/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 06:23:34 by doduwole          #+#    #+#             */
/*   Updated: 2023/03/12 13:49:51 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	init(int* signum, siginfo_t** info, void** context, int* pid)
{
	(void)*context;
	(void)*info;
	(void)*signum;
	if (*pid == 0)
		*pid = (*info)->si_pid;
}

void	sig_handler(int signum, siginfo_t* info, void* context)
{
	static int		pid;
	static char		c;
	static int		i;

	init(&signum, &info, &context, &pid);
	if (signum == SIGUSR1)
		c = (c << 1) | 1;
	else if (signum == SIGUSR2)
		c <<= 1;
	if (++i == 8)
	{
		i = 0;
		if (!c)
		{
			kill(pid, SIGUSR1);
			pid = 0;
			return;
		}
		ft_putchar_fd(c, 1);
		c = 0;
	}
	kill(pid, SIGUSR2);

}

int	main(void)
{
	struct sigaction	sa;

	ft_memset(&sa, 0, sizeof(sa));
	ft_putstrnbr_fd("Server PID: ", getpid());
	sa.sa_sigaction = sig_handler;
	sa.sa_flags = SA_RESTART | SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		ft_putstr_fd("Error sigaction\n", 1);
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		ft_putstr_fd("Error sigaction\n", 1);
	while (1)
		pause();
	return (0);
}
