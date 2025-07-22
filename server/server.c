/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radib <radib@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 14:44:43 by radib             #+#    #+#             */
/*   Updated: 2025/07/21 08:58:32 by radib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include "../libft/libft.h"
#include "../minitalk.h"
#include "../printf/ft_printf.h"

void	handle_signal(int sig, int x)
{
	int	bit;

	bit = malloc(sizeof (int));
	if (sig == SIGUSR1)
		bit |= x << 0;
	else if (sig == SIGUSR2)
		bit |= x << 1;
}

int	main(void)
{
	int					x;
	int					y;
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
		while (x )
			pause();
		ft_printf("%c", bit_to_character(bit, 0));
	}
	return (0);
}
