/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 08:36:40 by asalo             #+#    #+#             */
/*   Updated: 2024/03/26 10:25:14 by asalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minitalk.h"
// static int client_pid;

static void	action(int sig)
{
	static int	received = 0;

	if (sig == SIGUSR1)
		++received;
	else
	{
		ft_putnbr_fd(received, 1);
		ft_putchar_fd('\n', 1);
		exit(0);
	}
}

void	bit_sender(int pid, char i)
{
	int			bit;
	static int	count;

	bit = 0;
	while (bit < 8)
	{
		if ((i & (0x01 << bit)) != 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(40);
		bit++;
	}
	count++;
}
/*somehow make sender wait for the signal back from server before sending more*/

static void	middleman(int argc, char **argv, size_t len)
{
	// int					i;
	// size_t				len;
	// struct sigaction	*sa;
	if (argc != 3 || !argv[2][0])
	{
		ft_putstr_fd("Error: Incorrect format.\n", 2);
		ft_putstr_fd("Try: ./client <PID> <TEXT>\n", 1);
		exit (1);
	}
	if (len > MAX_LEN)
	{
		ft_putstr_fd("Error: Text too long!\n", 2);
		exit (1);
	}
}

int	main(int argc, char **argv)
{
	int		i;
	size_t	len;

	len = ft_strlen(argv[2]);
	middleman(argc, argv, len);
	ft_putstr_fd("Sent    : ", 1);
	ft_putnbr_fd(ft_strlen(argv[2]), 1);
	ft_putchar_fd('\n', 1);
	ft_putstr_fd("Received: ", 1);
	signal(SIGUSR1, action);
	signal(SIGUSR2, action);
	i = 0;
	while (argv[2][i] != '\0' && len > 0)
	{
		bit_sender(ft_atoi(argv[1]), argv[2][i]);
		i++;
		len--;
	}
	bit_sender(ft_atoi(argv[1]), '\n');
	while (1)
		pause();
	return (0);
	return (0);
}
