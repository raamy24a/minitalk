/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radib <radib@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 14:44:43 by radib             #+#    #+#             */
/*   Updated: 2025/07/31 15:48:19 by radib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include "../libft/libft.h"
#include "../minitalk.h"
#include "../printf/ft_printf.h"

void	handle_signal(int sig)
{
	static unsigned char				bit;
	static int							i;
	static int							pid;
	static int							pidcounter;

	if (pidcounter < 32)
	{
		if (sig == SIGUSR2)
			pid |= 1 << pidcounter;
		pidcounter++;
		return ;
	}
	if (sig == SIGUSR2)
		bit |= 1 << i;
	i++;
	if (i == 8)
	{
		write(1, &bit, 1);
		i = 0;
		bit = 0;
		kill(pid, SIGUSR1);
		usleep(100);
	}
}

int	main(void)
{
	int					x;
	struct sigaction	sa;

	x = getpid();
	sa.sa_handler = handle_signal;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_printf("%d\n", x);
	x = 0;
	while (1)
	{
		pause();
	}
	return (0);
}
