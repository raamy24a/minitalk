/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radib <radib@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 17:04:00 by radib             #+#    #+#             */
/*   Updated: 2025/04/24 13:49:11 by radib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*smot;
	unsigned char	cc;

	i = 0;
	cc = c;
	smot = (unsigned char *)s;
	while (i < n)
	{
		if (*smot == cc)
			return (smot);
		i++;
		smot++;
	}
	return (NULL);
}
// #include <stdio.h>

// int	main(void)
// {
// 	int	s[] = {1, 2, 3, 4, 5};

// 	printf("%p", ft_memchr(s, 2 + 256, 3));
// }
