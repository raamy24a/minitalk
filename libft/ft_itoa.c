/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radib <radib@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 17:11:13 by radib             #+#    #+#             */
/*   Updated: 2025/04/30 12:16:13 by radib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_number_sign(int n)
{
	int	sign;

	sign = 1;
	if (n < 0)
		sign = -1;
	return (sign);
}

static int	ft_itoasize(int n)
{
	size_t	i;
	int		n_copy;
	int		sign;

	i = 0;
	sign = 1;
	n_copy = n;
	if (n == -2147483648)
		return (11);
	if (n == 0)
		return (1);
	if (n_copy < 0)
	{
		n_copy *= -1;
		sign = -1;
	}
	while (n_copy > 0)
	{
		n_copy = n_copy / 10;
		i++;
	}
	if (sign == -1)
		return (i + 1);
	return (i);
}

static char	*ft_strcpy(char *dst, const char *src)
{
	size_t	i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_itoa(int n)
{
	char	*itoa_str;
	int		i;
	int		sign;

	i = ft_itoasize(n);
	itoa_str = malloc(sizeof(char) * (i + 1));
	if (!itoa_str)
		return (NULL);
	sign = ft_number_sign(n);
	if (n == 0)
		return (ft_strcpy(itoa_str, "0"));
	if (n == -2147483648)
		return (ft_strcpy(itoa_str, "-2147483648"));
	if (sign == -1)
		n *= -1;
	itoa_str[i] = '\0';
	while (n > 0)
	{
		itoa_str[i - 1] = n % 10 + '0';
		n = n / 10;
		i--;
	}
	if (sign == -1)
		itoa_str[i - 1] = '-';
	return (itoa_str);
}

// int	main(void)
// {
// 	printf("%s\n", ft_itoa(0));
// }