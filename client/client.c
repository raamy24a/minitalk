/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radib <radib@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 14:44:40 by radib             #+#    #+#             */
/*   Updated: 2025/08/11 04:05:48 by radib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"
#include "../libft/libft.h"

int	g_pid;

void	sendbyte(int pid, int character)
{
	int	i;

	i = 0;
	while (i != 8)
	{
		if ((character >> i) & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(100);
		i++;
	}
}

void	handle_signal(int sig)
{
	sendbyte(g_)
}

int	main(int argc, char *argv[])
{
	int		i;

	sa.sa_handler = handle_signal;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	sigaction(SIGUSR1, &sa, NULL);
	i = 0;
	if (argc != 3)
		return (0);
	g_pid = ft_atoi(argv[1]);
	sendbyte(g_pid, (int)argv[2][i]);
}
