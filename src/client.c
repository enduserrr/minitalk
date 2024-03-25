/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 08:36:40 by asalo             #+#    #+#             */
/*   Updated: 2024/03/25 09:53:09 by asalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minitalk.h"

void	bit_sender(int pid, char i)
{
	int	bit;

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
}

int	main(int argc, char **argv)
{
	int		i;
	size_t	len;

	if (argc != 3 || !argv[2][0])
	{
		ft_putstr_fd("Error: Incorrect format.\n", 2);
		ft_putstr_fd("Try: ./client <PID> <TEXT>\n", 1);
		exit (1);
	}
	len = ft_strlen(argv[2]);
	if (len > MAX_LEN)
	{
		ft_putstr_fd("Error: Text too long!\n", 2);
		exit (1);
	}
	i = 0;
	while (argv[2][i] != '\0' && len > 0)
	{
		bit_sender(ft_atoi(argv[1]), argv[2][i]);
		i++;
		len--;
	}
	bit_sender(ft_atoi(argv[1]), '\n');
	return (0);
}
