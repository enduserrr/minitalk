/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 11:35:51 by asalo             #+#    #+#             */
/*   Updated: 2024/03/23 19:38:54 by asalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MINITALK 
# define MINITALK

# include <signal.h>
# include <sys/types.h>
# include <unistd.h> /*getppid, */
# include <stdio.h>
# include <limits.h>
# include <stdlib.h> /*exit*/
# include <sys/proc.h> /*PID_MAX*/
# include "libft/incs/libft.h"

void		bit_sender(int pid, char i);
void		signalhandler(int sig);

#endif