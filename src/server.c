/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 08:37:28 by asalo             #+#    #+#             */
/*   Updated: 2024/03/26 10:27:29 by asalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minitalk.h"

void	signalhandler(int signal, siginfo_t *info, void *ucontent)
{
	static int	bit;
	static int	byte;
	static int	client_pid;

	(void)ucontent;
	if (!client_pid)
		client_pid = info->si_pid;
	if (signal == SIGUSR1)
		byte |= (0x01 << bit);
	bit++;
	if (bit == 8)
	{
		if (!byte)
		{
			kill(client_pid, SIGUSR2);
			client_pid = 0;
			return ;
		}
		ft_print_char(byte);
		kill(info->si_pid, SIGUSR1); /*send a signal back to the client*/
		bit = 0;
		byte = 0;
	}
}
/*int	main(int argc, char **argv)
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
}*/
static void	exiterror(int n)
{
	if (n == 0)
	{
		ft_putstr_fd("Error: incorrect format.\n", 2);
		ft_putstr_fd("Try: ./server\n", 1);
		exit(1);
	}
	if (n == 1)
	{
		 ft_putstr_fd("Error → Failed to send SIGUSR1", 2);
		 exit(1);
	}
	if (n == 2)
	{
		 ft_putstr_fd("Error → Failed to send SIGUSR2", 2);
		 exit(1);
	}
}
int	main(int argc, char **argv)
{
	int						pid;
	struct sigaction	*newsig;

	(void)argv;
	if (argc != 1)
		exiterror(0);
	pid = getpid();
	if (!pid)
		exit(1);
	ft_putstr_fd("-> ", 1);
	ft_putnbr_fd(pid, 1);
	ft_putstr_fd("\nWaiting for a message...\n", 1);
	newsig = ft_calloc(0, sizeof(newsig));
	newsig->sa_sigaction = &signalhandler;
	newsig->sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, newsig, NULL) == -1)
		exiterror(1);
	if (sigaction(SIGUSR2, newsig, NULL) == -1)
		exiterror(2);
	while (1)
		pause();
	return (0);
}