/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 20:51:03 by marvin            #+#    #+#             */
/*   Updated: 2024/08/08 20:51:03 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*p;
    unsigned char		ch;

	p = (const unsigned char*)s;
	ch = (unsigned char)c;
    while (n)
	{
        if (*p == ch)
            return ((void*)p);
		p++;
		n--;
    }

    return (NULL);
}
