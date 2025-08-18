/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radib <radib@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 14:46:15 by radib             #+#    #+#             */
/*   Updated: 2025/04/24 13:49:41 by radib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*ptr_src;
	char	*ptr_dest;
	size_t	i;

	ptr_src = (char *)src;
	ptr_dest = (char *)dest;
	if (!ptr_dest && !ptr_src)
		return (NULL);
	if (ptr_dest > ptr_src)
	{
		while (n -- > 0)
			ptr_dest[n] = ptr_src[n];
	}
	else
	{
		i = 0;
		while (i ++ < n)
			ptr_dest[i - 1] = ptr_src[i - 1];
	}
	return (dest);
}
/*

int	main(void)
{
	char	src[] = "12345";
	char	dest[] = "12345";

	ft_memmove(src, src + 2, 1);
	printf("MINE: %s\n", src);
	memmove(dest, dest + 2, 1);
	printf("VRAI: %s\n ", dest);
}
*/
