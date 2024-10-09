/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 09:45:43 by marvin            #+#    #+#             */
/*   Updated: 2024/08/11 09:45:43 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new_element)
{
	t_list	*last;
	if (lst)
	{
		if (*lst)
		{
			last = ft_lstlast((*lst));
			last -> next = new_element;
		}
		else
			(*lst) = new_element;
	}
}
