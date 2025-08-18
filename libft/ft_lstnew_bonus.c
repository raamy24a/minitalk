/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radib <radib@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 13:34:31 by radib             #+#    #+#             */
/*   Updated: 2025/04/25 12:27:18 by radib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(void *content)
{
	t_list	*i_list;

	i_list = malloc(sizeof(t_list));
	if (!i_list)
		return (NULL);
	i_list -> content = content;
	i_list -> next = NULL;
	return (i_list);
}
