/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 06:23:34 by doduwole          #+#    #+#             */
/*   Updated: 2023/03/20 06:08:45 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_bin_to_char(int signum, char *c)
{
	if (signum == SIGUSR1)
		*c = (*c << 1) | 1;
	else if (signum == SIGUSR2)
		*c <<= 1;
}

void	sig_handler(int signum, siginfo_t *info, void *context)
{
	static int		pid;
	static char		c;
	static int		i;

	(void)context;
	if (pid == 0)
		pid = info->si_pid;
	ft_bin_to_char(signum, &c);
	if (++i == 8)
	{
		i = 0;
		if (!c)
		{
			kill(pid, SIGUSR1);
			pid = 0;
			return ;
		}
		ft_putchar_fd(c, 1);
		c = 0;
	}
	kill(pid, SIGUSR2);
}

int	main(void)
{
	struct sigaction	sa;

	ft_putstrnbr_fd("Server PID: ", getpid());
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_RESTART | SA_SIGINFO;
	sa.sa_sigaction = sig_handler;
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		ft_putstr_fd("Error sigaction\n", 1);
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		ft_putstr_fd("Error sigaction\n", 1);
	while (1)
		pause();
	return (0);
}
