/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radib <radib@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 14:44:40 by radib             #+#    #+#             */
/*   Updated: 2025/08/19 14:44:49 by radib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"
#include "../libft/libft.h"

int	g_handshake;

void	sendbyte(int pid, int character, int i)
{
	while (i != 8)
	{
		g_handshake = 0;
		if (((character >> i) & 1) == 1)
		{
			if (kill(pid, SIGUSR2))
			{
				write(2, "wrong pid\n", 10);
				exit (0);
			}
		}
		else
		{
			if (kill(pid, SIGUSR1))
			{
				write(2, "wrong pid\n", 10);
				exit (0);
			}
		}
		while (g_handshake == 0)
			usleep(1);
		i++;
	}
}

void	handler(int sig)
{
	if (sig == SIGUSR1)
		ft_printf("%s", "bit_received \n");
	g_handshake = 1;
}

int	main(int argc, char *argv[])
{
	int					i;
	struct sigaction	sa;
	int					pid;

	sa.sa_handler = handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	sigaction(SIGUSR1, &sa, NULL);
	i = 0;
	if (argc != 3)
		return (0);
	pid = ft_atoi(argv[1]);
	while (argv[2][i])
	{
		sendbyte(pid, argv[2][i], 0);
		i++;
	}
	return (0);
}
