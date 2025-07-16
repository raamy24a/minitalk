/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radib <radib@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 14:44:43 by radib             #+#    #+#             */
/*   Updated: 2025/07/16 07:53:15 by radib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include "../libft/libft.h"
#include "../minitalk.h"
#include "../printf/ft_printf.h"

t_bit	g_globalbit;

void handle_signal(int sig)
{
	if (sig == SIGUSR1)
		g_globalbit.bit[g_globalbit.i] = '0';
	else if (sig == SIGUSR2)
		g_globalbit.bit[g_globalbit.i] = '1';
	g_globalbit.i++;
}
char	bit_to_character(char *bit, int total)
{
	int	i;
	int	j;
	int	max;
	int	temp;

	i = 0;
	max = 128;
	j = 0;
	while (bit[i])
	{
		temp = max;
		if (bit[i] == '1')
		{
			while (i != j)
			{
				temp /= 2;
				j++;
			}
			total += temp;
			j = 0;
		}
		i++;
	}
	return (total);
}

int	main(void)
{
	int			x;
	struct sigaction sa;

	g_globalbit.bit[8] = '\0';
	x = getpid();

	sa.sa_handler = handle_signal;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;

	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_printf("%d\n", x);
	while (1)
	{
		while (g_globalbit.i != 8)
			pause();
		ft_printf("%c", bit_to_character(g_globalbit.bit, 0));
		g_globalbit.i = 0;
	}
	return (0);
}
