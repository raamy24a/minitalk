/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radib <radib@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 14:44:40 by radib             #+#    #+#             */
/*   Updated: 2025/07/29 14:56:24 by radib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"
#include "../libft/libft.h"

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

int	main(int argc, char *argv[])
{
	int		i;
	int		pid;

	i = 0;
	if (argc != 3)
		return (0);
	pid = ft_atoi(argv[1]);
	while (argv[2][i])
	{
		sendbyte(pid, (int)argv[2][i]);
		i++;
	}
}
