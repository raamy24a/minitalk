/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radib <radib@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 15:53:44 by radib             #+#    #+#             */
/*   Updated: 2025/04/16 17:23:25 by radib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char			*smot;
	size_t			i;
	unsigned char	uc;

	smot = (char *)s;
	uc = (unsigned char)c;
	i = 0;
	while (smot[i])
		i++;
	if (uc == '\0')
		return (smot + i);
	while (i > 0)
	{
		i--;
		if (smot[i] == uc)
			return (smot + i);
	}
	return (NULL);
}
// int	main(void)
// {
// 	char	s2[] = "league of legendll";

// 	printf("%s\n", ft_strrchr(s2, 'l'));
// }
