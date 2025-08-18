/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radib <radib@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 14:01:31 by radib             #+#    #+#             */
/*   Updated: 2025/04/30 12:20:39 by radib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// char	f(unsigned int i, char c)
// {
// 	c += i;
// 	return (c++);
// }

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*str_api;

	i = 0;
	if (!s || !f)
		return (NULL);
	while (s[i])
		i++;
	str_api = malloc(sizeof(char) * i + 1);
	if (!str_api)
		return (NULL);
	i = 0;
	while (s[i])
	{
		str_api[i] = f(i, s[i]);
		i++;
	}
	str_api[i] = '\0';
	return (str_api);
}
/*
int	main(void)
{
	printf("texte +1 + position %s\n", ft_strmapi("vive fortnite", f));
	return (0);
}
*/
