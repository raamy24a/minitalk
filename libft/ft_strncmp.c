/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radib <radib@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 16:07:21 by radib             #+#    #+#             */
/*   Updated: 2025/04/17 14:13:29 by radib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while ((*s1 - *s2 == 0 && (*s1 != '\0' && *s2 != '\0') && i < n))
	{
		if (*s1 != '\0')
			s1++;
		if (*s2 != '\0')
			s2++;
		i++;
	}
	if (i == n)
	{
		s1--;
		s2--;
	}
	return ((unsigned char) *s1 - (unsigned char) *s2);
}

// int	main(void)
// {
// 	char s1[] = "bonjo1";
// 	char s2[] = "bonjour";

// 	printf("%d\n", ft_strncmp(s1, s2, 5));
// }
