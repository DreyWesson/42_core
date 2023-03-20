/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 08:38:26 by doduwole          #+#    #+#             */
/*   Updated: 2023/03/19 11:35:33 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	g_receiver;

void	sig_handler(int n, siginfo_t *info, void *context)
{
	static int	i;

	(void)context;
	(void)info;
	(void)n;
	g_receiver = 1;
	if (n == SIGUSR2)
		i++;
	else if (n == SIGUSR1)
		ft_putstrnbr_fd("Num of bytes received -> ", i / 8);
}

int	ft_char_to_bin(char c, int pid)
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
				ft_putendl_fd("No response from server.", 1);
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

int	main(int argc, char *argv[])
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
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_RESTART | SA_SIGINFO;
	sa.sa_sigaction = sig_handler;
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		ft_putstr_fd("Error sigaction\n", 1);
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		ft_putstr_fd("Error sigaction\n", 1);
	while (argv[2][byte_index])
		ft_char_to_bin(argv[2][byte_index++], pid);
	ft_char_to_bin('\0', pid);
	return (0);
}
