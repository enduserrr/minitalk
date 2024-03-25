/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 08:37:28 by asalo             #+#    #+#             */
/*   Updated: 2024/03/25 09:11:16 by asalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minitalk.h"

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

int	main(int argc, char **argv)
{
	int	pid;

	(void)argv;
	if (argc != 1)
	{
		ft_putstr_fd("Error: incorrect format.\n", 2);
		ft_putstr_fd("Try: ./server\n", 1);
		exit(1);
	}
	pid = getpid();
	if (!pid || pid <= 0)
		exit(1);
	ft_putstr_fd("-> ", 1);
	ft_putnbr_fd(pid, 1);
	ft_putstr_fd("\nWaiting for a message...\n", 1);
	while (argc == 1)
	{
		signal(SIGUSR1, signalhandler);
		signal(SIGUSR2, signalhandler);
		pause();
	}
	return (0);
}
