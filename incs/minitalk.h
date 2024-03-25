/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 11:35:51 by asalo             #+#    #+#             */
/*   Updated: 2024/03/25 09:51:31 by asalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# define MAX_LEN 10000

/**
 * @brief	To ensure correct printing of special chars like backslashes
 * 			and double quotes, they must be escaped properly.
 * 			To print a backslash \, escape it as \\ ("\\"),
 * 			and for a double quote(") within a double-quoted string,
 * 			you need to escape it as \" (""\"\").
*/
# include <signal.h>
# include "libft/incs/libft.h"

void		bit_sender(int pid, char i);
void		signalhandler(int sig);

#endif
