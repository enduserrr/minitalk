/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 11:35:51 by asalo             #+#    #+#             */
/*   Updated: 2024/03/24 15:38:55 by asalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# define MAX_LEN 10005

/**
 * @brief	ft_atoi (ft_lookup_space) + ft_print_char + usleep(10)
 * 			=> str of 110 chars
 * 			ft_atoi (ft_lookup_space) + write(1, &c, 1) + usleep(10)
 * 			=> str of 60 chars
 * 
 * 			To ensure correct printing of special characters like backslashes
 * 			and double quotes, you can escape them properly.
 * 			For example, to print a backslash \, you need to escape it as \\,
 * 			and to print a double quote " within a double-quoted string,
 * 			you need to escape it as \".
*/
# include <signal.h>
# include "libft/incs/libft.h"

void		bit_sender(int pid, char i);
void		signalhandler(int sig);

#endif
