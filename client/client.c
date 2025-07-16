/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radib <radib@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 14:44:40 by radib             #+#    #+#             */
/*   Updated: 2025/07/16 08:14:04 by radib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"
#include "../libft/libft.h"

void	sendbyte(int pid, int character)
{
	char	bits[9];
	int		i;

	i = 0;
	while (i != 8)
	{
		bits[i] = character % 2 + '0';
		i++;
		character /= 2;
	}
	if (character == 0)
		bits[i] = '0';
	else
		bits[i] = '1';
	bits[8] = '\0';
	while (i >= 0)
	{
		if (bits[i] == '1')
			kill(pid, SIGUSR2);
		else if (bits[i] == '0')
			kill(pid, SIGUSR1);
		usleep(100);
		i--;
	}
}
int	main(int argc, char *argv[])
{
	int		i;
	int		pid;

	i = 0;
	pid = ft_atoi(argv[1]);
	while (argv[2][i])
	{
		sendbyte(pid, 29);
		i++;
	}
}
