/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 06:23:34 by doduwole          #+#    #+#             */
/*   Updated: 2023/03/07 15:32:52 by doduwole         ###   ########.fr       */
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
		write(1, &c, 1);
		c = 0;
	}
	kill(pid, SIGUSR2);
	return;
}

int	main(void)
{
	struct sigaction	sa;

	ft_memset(&sa, 0, sizeof(sa));
	sigemptyset(&sa.sa_mask); // Empty s_maskThe sa_mask variable is a variable that contains signals to be blocked while processing them. A signal block is an operation method that reserves the signal set in sa_mask to the operating system to be processed later. Therefore, if the signals in the sa_mask variable are emptied through the sigemptyset() function, all signals are not blocked.
	ft_putstrnbr_fd("Server PID: ", getpid());
	sa.sa_sigaction = sig_handler;
	sa.sa_flags = SA_RESTART | SA_SIGINFO;
	sa.sa_flags = SA_RESTART;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		ft_putstr_fd("Error sigaction\n", 1);
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		ft_putstr_fd("Error sigaction\n", 1);
	while (1)
		pause(); // pause() function is converted to a standby state until a signal is received. We need the pause function because we need to continuously receive bits.
	return (0);
}
