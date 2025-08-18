/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radib <radib@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 18:13:03 by radib             #+#    #+#             */
/*   Updated: 2025/04/29 14:28:08 by radib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int		sign;
	long	total;

	total = 0;
	sign = 1;
	while ((*nptr >= 9 && *nptr <= 13) || *nptr == ' ')
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign *= -1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		total *= 10;
		total += *nptr - '0';
		if ((total < 0) && sign == -1)
			return (0);
		if ((total < 0) && sign == 1)
			return (-1);
		nptr++;
	}
	return (total * sign);
}

// int	main(void)
// {
// 	printf("monn atoi : %d\n", ft_atoi("15156156159151561"));
// 	printf("vrai atoi : %d\n", atoi("15156156159151561"));
// }
