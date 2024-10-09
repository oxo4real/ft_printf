/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 10:16:14 by marvin            #+#    #+#             */
/*   Updated: 2024/08/11 10:16:14 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*next;

	if (lst && del)
	{
		while (*lst)
		{
			next = (*lst) -> next;
			ft_lstdelone((*lst), del);
			(*lst) = next; 
		}
		(*lst) = NULL;
	}
}
