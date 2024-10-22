/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 20:58:55 by marvin            #+#    #+#             */
/*   Updated: 2024/08/08 20:58:55 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*p1;
	const unsigned char	*p2;

	p1 = (const unsigned char *)s1;
	p2 = (const unsigned char *)s2;
	while (n)
	{
		if (*p1 < *p2)
			return (*p1 - *p2);
		if (*p1 > *p2)
			return (*p1 - *p2);
		p1++;
		p2++;
		n--;
	}
	return (0);
}
