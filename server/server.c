/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radib <radib@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 14:44:43 by radib             #+#    #+#             */
/*   Updated: 2025/08/11 14:49:25 by radib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include "../libft/libft.h"
#include "../minitalk.h"
#include "../printf/ft_printf.h"

void	handler(int sig, siginfo_t *info, void *ucontext)
{
	static char	bit;
	static int	i;

	(void) ucontext;
	if (sig == SIGUSR2)
		bit |= 1 << i;
	i++;
	if (i == 8)
	{
		write (1, &bit, 1);
		i = 0;
		bit = 0;
	}
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	int					x;
	struct sigaction	sa;

	x = getpid();
	sa.sa_sigaction = handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
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
