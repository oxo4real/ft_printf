/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 10:25:29 by marvin            #+#    #+#             */
/*   Updated: 2024/08/11 10:25:29 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*new_link;
	void	*new_content;

	new_lst = NULL;
	if (lst && f && del)
	{
		while (lst)
		{
			new_content = f(lst -> content);
			new_link = ft_lstnew(new_content);
			if (!new_link)
			{
				del(new_content);
				ft_lstclear(&new_lst, del);
				return (NULL);
			}
			ft_lstadd_back(&new_lst, new_link);
			lst = lst -> next;
		}
	}
	return (new_lst);
}
