/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radib <radib@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 14:44:40 by radib             #+#    #+#             */
/*   Updated: 2025/07/31 15:51:33 by radib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"
#include "../libft/libft.h"
#include <unistd.h>
#include <signal.h>

t_pid_and_count	g_pid_and_count;

void	sendpid(int pid)
{
	int	i;

	i = 0;
	while (i < 32)
	{
		if ((pid >> i) & 1)
			kill(g_pid_and_count.pid, SIGUSR2);
		else
			kill(g_pid_and_count.pid, SIGUSR1);
		usleep(1000);
		i++;
	}
}

void	sendbyte(int sig)
{
	int	i;

	i = 0;
	if (sig == SIGUSR1)
	{
		while (i < 8)
		{
			if ((g_pid_and_count.string[g_pid_and_count.i] >> i) & 1)
				kill(g_pid_and_count.pid, SIGUSR2);
			else
				kill(g_pid_and_count.pid, SIGUSR1);
			i++;
			usleep(1000);
		}
		g_pid_and_count.i++;
	}
}

int	main(int argc, char *argv[])
{
	struct sigaction	sa;
	int					x;

	g_pid_and_count.i = 0;
	g_pid_and_count.string = argv[2];
	x = getpid();
	sa.sa_handler = sendbyte;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	sigaction(SIGUSR1, &sa, NULL);
	if (argc != 3)
		return (0);
	g_pid_and_count.pid = ft_atoi(argv[1]);
	sendpid(x);
	while (1)
	{
		if (g_pid_and_count.string[g_pid_and_count.i] == 0)
		{
			sendbyte(SIGUSR1);
			return (0);
		}
	}
}
