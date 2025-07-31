/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radib <radib@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 14:44:43 by radib             #+#    #+#             */
/*   Updated: 2025/07/29 14:38:07 by radib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include "../libft/libft.h"
#include "../minitalk.h"
#include "../printf/ft_printf.h"

t_bit	g_bit;

void	handle_signal(int sig)
{
	if (sig == SIGUSR1)
		g_bit.bit |= g_bit.i << 0;
	else if (sig == SIGUSR2)
		g_bit.bit |= g_bit.i << 1;
	g_bit.i++;
}

int	main(void)
{
	int					x;
	struct sigaction	sa;

	x = getpid();
	sa.sa_handler = handle_signal;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	g_bit.i = 0;
	g_bit.bit = 0;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_printf("%d\n", x);
	x = 0;
	while (1)
	{
		while (g_bit.i != 8)
			pause();
		ft_printf("%c", (g_bit.bit));
		g_bit.i = 0;
	}
	return (0);
}
