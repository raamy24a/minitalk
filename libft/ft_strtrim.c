/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radib <radib@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 11:24:44 by radib             #+#    #+#             */
/*   Updated: 2025/04/30 12:00:07 by radib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

static int	ft_trimm_start(char const *s1, char const *set)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s1[i])
	{
		while (set[j] != s1[i] && set[j])
			j++;
		if (!(set[j]))
			break ;
		j = 0;
		i++;
	}
	return (i);
}

static int	ftend(char const *s1, char const *set)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s1[i])
		i++;
	i--;
	while (s1[i])
	{
		while (set[j] != s1[i] && set[j])
			j++;
		if (!(set[j]))
			break ;
		j = 0;
		i--;
	}
	return (i + 1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		end;
	char	*str_trimmed;

	i = 0;
	if (!s1)
		return (NULL);
	if (!set)
		return ((char *)s1);
	end = ftend(s1, set);
	if (ft_trimm_start(s1, set) > end - 1)
	{
		str_trimmed = malloc(1);
		if (!str_trimmed)
			return (NULL);
		str_trimmed[0] = '\0';
		return (str_trimmed);
	}
	str_trimmed = malloc(sizeof(char) * (end - ft_trimm_start(s1, set) + 1));
	if (!str_trimmed)
		return (NULL);
	while (i++ < end - ft_trimm_start(s1, set))
		str_trimmed[i - 1] = s1[ft_trimm_start(s1, set) + i - 1];
	str_trimmed[i - 1] = '\0';
	return (str_trimmed);
}

// int	main(void)
// {
// 	printf("%s\n", ft_strtrim("abcdba", NULL ));
// }
