/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 08:38:26 by doduwole          #+#    #+#             */
/*   Updated: 2023/03/05 08:29:01 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/**
 * https://www.thegeekstuff.com/2012/03/linux-signals-fundamentals/
 * https://www.thegeekstuff.com/2012/03/catch-signals-sample-c-code/
 * https://velog.io/tags/minitalk
 * https://linuxhint.com/signal_handlers_c_programming_language/
 * https://stackoverflow.com/questions/231912/what-is-the-difference-between-sigaction-and-signal
*/

#include "minitalk.h"

static int	g_receiver;

void	sig_handler(int n)
{
	static int	i;

	g_receiver = 1;
	if (n == SIGUSR2)
		i++;
	if (n == SIGUSR1)
	{
		ft_putstrnbr_fd("Num of bytes received ->", i / 8);
		exit(0);
	}
	return;
}

int	conversion(char c, int pid)
{
	int	n;
	int	bit_index;

	bit_index = 7;
	while (bit_index >= 0)
	{
		n = 0;
		// if (c & (1 << bit_index)) // converts each char -> binary
		if ((c >> bit_index) & 1) // converts each char -> binary
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		while (g_receiver == 0) // handles no response from server
		{
			if (n == 42)
			{
				write(1, "No response from server.\n", 26);
				exit(1);
			}
			n++;
			usleep(100); // A bit of delay is required because the //kill function will send a repetitive signal to the server unilaterally.
		}
		g_receiver = 0;
		bit_index--;
	}
	return (0);
}

int	main(int argc, char* argv[])
{
	int		byte_index;
	int	n;

	if (argc != 3)
	{
		// write(1, "too few args!\n", 14);
		ft_putstrnbr_fd("You need to pass 2 args but u passed ", argc - 1);
		return (1);
	}
	byte_index = 0;
	n = ft_atoi(argv[1]); // convert pid from str->num
	signal(SIGUSR1, sig_handler);
	signal(SIGUSR2, sig_handler);
	while (argv[2][byte_index])
		conversion(argv[2][byte_index++], n);
	conversion(0, n); // handles multiple calls
	return (0);
}
