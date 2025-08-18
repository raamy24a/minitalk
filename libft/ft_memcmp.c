/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radib <radib@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 17:15:19 by radib             #+#    #+#             */
/*   Updated: 2025/04/24 13:49:34 by radib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*s1c;
	unsigned char	*s2c;

	i = 0;
	s1c = (unsigned char *)s1;
	s2c = (unsigned char *)s2;
	while (i < n)
	{
		if (s1c[i] - s2c[i] != 0)
			return (s1c[i] - s2c[i]);
		i++;
	}
	return (0);
}
// #include <stdio.h>

// int	main(void)
// {
// 	char	s2[] = {0, 0, 127, 0};
// 	char	s3[] = {0, 0, 42, 0};

// 	printf("%d\n", ft_memcmp(s2, s3, 4));
// }
