/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radib <radib@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 15:53:46 by radib             #+#    #+#             */
/*   Updated: 2025/04/24 10:24:57 by radib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	size_t	i;
	t_list	*temp;

	i = 0;
	temp = lst;
	if (temp == NULL)
		return (0);
	while (temp -> next)
	{
		temp = temp -> next;
		i++;
	}
	return (i + 1);
}
