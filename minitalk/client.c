/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 08:38:26 by doduwole          #+#    #+#             */
/*   Updated: 2023/03/12 12:57:54 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/**
 * https://www.thegeekstuff.com/2012/03/linux-signals-fundamentals/
 * https://www.thegeekstuff.com/2012/03/catch-signals-sample-c-code/
 * https://velog.io/tags/minitalk
 * https://linuxhint.com/signal_handlers_c_programming_language/
 * https://stackoverflow.com/questions/231912/what-is-the-difference-between-sigaction-and-signal
 * cat ./text.txt|xargs -0 ./client 44545
*/

#include "minitalk.h"

static int	g_receiver;

void	sig_handler(int n, siginfo_t* info, void* context)
{
	static int	i;

	(void)context;
	(void)info;
	(void)n;
	g_receiver = 1;
	if (n == SIGUSR2)
		i++;
	else if (n == SIGUSR1)
	{
		ft_putstrnbr_fd("Num of bytes received ->", i / 8);
		exit(0);
	}
}

int	conversion(char c, int pid)
{
	int	itr;
	int	bit_index;

	bit_index = 7;
	while (bit_index >= 0)
	{
		itr = 0;
		if ((c >> bit_index) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		while (g_receiver == 0)
		{
			if (itr == 50)
			{
				write(1, "No response from server.\n", 26);
				exit(1);
			}
			itr++;
			usleep(100);
		}
		g_receiver = 0;
		bit_index--;
	}
	return (0);
}

int	main(int argc, char* argv[])
{
	struct sigaction	sa;
	int					byte_index;
	int					pid;


	if (argc != 3)
	{
		ft_putstrnbr_fd("You need to pass 2 args but u passed ", argc - 1);
		return (1);
	}
	byte_index = 0;
	pid = ft_atoi(argv[1]);
	ft_memset(&sa, 0, sizeof(sa));
	sa.sa_sigaction = sig_handler;
	sa.sa_flags = SA_RESTART | SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		ft_putstr_fd("Error sigaction\n", 1);
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		ft_putstr_fd("Error sigaction\n", 1);
	while (argv[2][byte_index])
		conversion(argv[2][byte_index++], pid);
	conversion('\0', pid);
	return (0);
}
