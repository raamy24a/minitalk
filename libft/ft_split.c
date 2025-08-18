/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radib <radib@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 12:47:21 by radib             #+#    #+#             */
/*   Updated: 2025/04/30 12:12:26 by radib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**array_words_malloc(char const *s, char c)
{
	size_t	i;
	size_t	words_count;
	size_t	j;
	char	**ptr_split;

	words_count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		j = i;
		while (s[i] && s[i] != c)
			i++;
		if (i != j)
			words_count++;
	}
	ptr_split = malloc((sizeof(char *)) * (words_count + 1));
	if (!ptr_split)
		return (NULL);
	return (ptr_split);
}

static char	**words_malloc(char const *s, char c, char **ptr_split)
{
	size_t	j;
	size_t	words_count;
	size_t	i;

	words_count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] == '\0')
			break ;
		j = i;
		while (s[i] && s[i] != c)
			i++;
		ptr_split[words_count] = malloc(sizeof(char) * (i - j + 1));
		if (!ptr_split[words_count])
		{
			while (words_count--)
				free(ptr_split[words_count]);
			return (NULL);
		}
		words_count++;
	}
	return (ptr_split);
}

static char	**ft_split_write(char const *s, char c, char **ptr_split)
{
	size_t	words_count;
	size_t	i;
	size_t	j;

	words_count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] == '\0')
			break ;
		j = 0;
		while (s[i] && s[i] != c)
		{
			ptr_split[words_count][j] = s[i];
			i++;
			j++;
		}
		ptr_split[words_count][j] = '\0';
		words_count++;
	}
	ptr_split[words_count] = NULL;
	return (ptr_split);
}

char	**ft_split(char const *s, char c)
{
	char	**ptr_split;

	if (!s)
		return (NULL);
	ptr_split = array_words_malloc(s, c);
	if (!ptr_split)
		return (NULL);
	if (!words_malloc(s, c, ptr_split))
	{
		free(ptr_split);
		return (NULL);
	}
	ft_split_write(s, c, ptr_split);
	return (ptr_split);
}

// int	main(void)
// {
// 	char	**ptr_split;
// 	int		i;

// 	ptr_split = ft_split("", ' ');
// 	if (!ptr_split)
// 	{
// 		printf("(null)\n");
// 		return (0);
// 	}
// 	i = 0;
// 	while (ptr_split[i])
// 	{
// 		printf("%s\n", ptr_split[i]);
// 		free(ptr_split[i]);
// 		i++;
// 	}
// 	free(ptr_split);
// 	return (0);
// }
