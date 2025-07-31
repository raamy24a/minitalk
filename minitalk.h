/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radib <radib@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 13:20:31 by radib             #+#    #+#             */
/*   Updated: 2025/07/31 15:26:35 by radib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# include "printf/ft_printf.h"
# include <stdio.h>
# include <unistd.h>
# include <signal.h>

typedef struct pid_and_count
{
	int		pid;
	int		i;
	char	*string;
}	t_pid_and_count;

#endif
