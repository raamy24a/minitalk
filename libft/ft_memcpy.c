/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radib <radib@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 13:08:06 by radib             #+#    #+#             */
/*   Updated: 2025/04/24 10:28:17 by radib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*ptr_src;
	char	*ptr_dest;
	size_t	i;

	ptr_src = (char *)src;
	ptr_dest = (char *)dest;
	if (!ptr_dest && !ptr_src)
		return (NULL);
	i = 0;
	while (i < n)
	{
		ptr_dest[i] = ptr_src[i];
		i++;
	}
	return (dest);
}
/*
int	main(void)
{
	char	src[] = "BONJOUR";

	char dest[] ="bonjour";
	printf("%s\n%s\n", dest ,src);
	ft_memcpy(dest, src, 7);
	printf("%s\n%s\n", dest ,src);
}
*/
