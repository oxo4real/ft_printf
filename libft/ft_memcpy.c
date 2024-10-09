/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 19:20:05 by marvin            #+#    #+#             */
/*   Updated: 2024/08/08 19:20:05 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
    const unsigned char	*s;

	if (dest || src)
	{
		d = (unsigned char *)dest;
		s = (const unsigned char *)src;
		while (n)
		{
			*d = *s;
			n--;
			d++;
			s++;
		}
	}
    return (dest);
}
