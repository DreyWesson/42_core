/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 08:38:26 by doduwole          #+#    #+#             */
/*   Updated: 2023/03/02 12:20:39 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/**
 * https://www.thegeekstuff.com/2012/03/linux-signals-fundamentals/
 * https://www.thegeekstuff.com/2012/03/catch-signals-sample-c-code/
 * https://linuxhint.com/signal_handlers_c_programming_language/
*/

#include "minitalk.h"

void	ft_message(char c, pid_t pid)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if ((c >> i) & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(80);
		i--;
	}
}

int	main(int argc, char** argv)
{
	int	pid;
	int	i;

	i = 0;
	if (argc != 3)
	{
		write(1, "too few args. terminal ./client {PID} {s}\n", 42);
		return (0);
	}
	pid = ft_atoi(argv[1]);
	while (argv[2][i])
	{
		ft_message(argv[2][i], pid);
		i++;
	}
	return (0);
}
