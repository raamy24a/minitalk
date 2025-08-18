/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radib <radib@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 21:09:32 by radib             #+#    #+#             */
/*   Updated: 2025/04/24 13:44:07 by radib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nb, size_t size)
{
	void	*calloced;

	if (size != 0 && nb > 4294967295 / size)
		return (NULL);
	calloced = malloc(nb * size);
	if (!calloced)
		return (NULL);
	ft_memset(calloced, 0, nb * size);
	return ((void *)calloced);
}

// int	main(void)
// {
// 	char	*bjr;

// 	bjr = ft_calloc(8, sizeof(char));

// 	printf("%s\n", bjr);
// 	free(bjr);
// }
