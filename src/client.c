/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 08:36:40 by asalo             #+#    #+#             */
/*   Updated: 2024/03/23 19:57:22 by asalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minitalk.h"

/**
 * @brief	The function 'sleep()' and 'usleep()' both hault the program
 * 			execution process for a specified time.
 * 			- 'sleep(0)' deals in seconds
 * 			- 'usleep(0,000,000)' deals in microseconds
*/

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
		usleep(10);
		bit++;
	}
}

int	main(int argc, char **argv)
{
	int		pid;
	int		i;
	size_t	len;

	i = 0;
	if (argc == 3)
	{
		pid = ft_atol(argv[1]);
		len = ft_strlen(argv[2]);
		while (argv[2][i] != '\0' && len > 0)
		{
			bit_sender(pid, argv[2][i]);
			i++;
			len--;
		}
		bit_sender(pid, '\n');
	}
	else
	{
		ft_putstr_fd("Error: wrong format.\n", 2);
		ft_putstr_fd("Try: ./client <PID> <MESSAGE>\n", 1);
		exit (1);
	}
	exit (0);
}

