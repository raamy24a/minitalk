/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radib <radib@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 14:44:40 by radib             #+#    #+#             */
/*   Updated: 2025/07/15 16:19:54 by radib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "../minitalk.h"

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
	while (bits[i])
	{
		if (bits[i] == '1')
			kill(pid, SIGUSR2);
		else if (bits[i] == '0')
			kill(pid, SIGUSR1);
		i--;
	}
}
int	main(int argc, char *argv[])
{
	int		i;
	int		pid;

	i = 0;
	if (argc != 2)
		return (0);
	pid = argv[1];
	while (argv[2][i])
	{
		sendbyte(pid, 29);
		i++;
	}
}
