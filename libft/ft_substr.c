/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radib <radib@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 11:01:58 by radib             #+#    #+#             */
/*   Updated: 2025/04/30 11:50:19 by radib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub_str;
	size_t	i;

	if (s == NULL)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		sub_str = malloc(sizeof(char));
		if (!sub_str)
			return (NULL);
		sub_str[0] = '\0';
		return (sub_str);
	}
	if (len > ft_strlen(s) - start)
		sub_str = malloc(sizeof(char) * (ft_strlen(s) - start + 1));
	else
		sub_str = malloc(sizeof(char) * (len + 1));
	i = 0;
	if (!sub_str)
		return (NULL);
	while (i++ < len && s[i - 1 + start])
		sub_str[i - 1] = s[i - 1 + start];
	sub_str[i - 1] = '\0';
	return (sub_str);
}
