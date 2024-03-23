/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 08:37:28 by asalo             #+#    #+#             */
/*   Updated: 2024/03/23 18:46:43 by asalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minitalk.h"

/**
 * @brief Program won't shutdown without a failure or a shutdown signal
*/

void	signalhandler(int signal)
{
	static int	bit;
	static int	byte;

	if (signal == SIGUSR1)
		byte |= (0x01 << bit);
	bit++;
	if (bit == 8)
	{
		ft_print_char(byte);
		bit = 0;
		byte = 0;
	}
}

/**
 * @brief	The function 'pause()' haults the calling process
 * 			until a signal is received.
*/

int	main(int argc, char **argv)
{
	long int	pid;

	(void)argv;
	if (argc != 1)
	{
		ft_putstr_fd("Error: incorrect format.\n", 2);
		ft_putstr_fd("Try: ./server\n", 1);
		exit(1);
	}
	pid = getpid();
	if (!pid || pid > INT_MAX || pid <= 0)
		exit(1);
	ft_putstr_fd("-> ", 1);
	ft_putnbr_fd((int)pid, 1);
	ft_putstr_fd("\nWaiting for a message...\n", 1);
	while (argc == 1)
	{
		signal(SIGUSR1, signalhandler);
		signal(SIGUSR2, signalhandler);
		pause();
	}
	return (0);
}
