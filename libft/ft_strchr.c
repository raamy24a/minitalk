/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radib <radib@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 15:34:38 by radib             #+#    #+#             */
/*   Updated: 2025/04/16 17:20:05 by radib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	*smot;
	char			*mot_final;
	size_t			i;
	unsigned char	uc;

	i = 0;
	uc = (unsigned char)c;
	mot_final = (char *)s;
	smot = (unsigned char *)s;
	while (smot[i])
	{
		if (smot[i] == uc)
			return (mot_final + i);
		i++;
	}
	if (uc == '\0')
		return (mot_final + i);
	return (NULL);
}
// int	main(void)
// {
// 	char	s[] = "tortelini";

// 	printf("%s\n", ft_strchr(s, 't'+ 256));
// }
