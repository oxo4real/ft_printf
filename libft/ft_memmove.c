/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 19:39:22 by marvin            #+#    #+#             */
/*   Updated: 2024/08/08 19:39:22 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	if (dest || src)
	{
		d = (unsigned char *)dest;
		s = (const unsigned char *)src;
		if (s < d)
		{
			s += n - 1;
			d += n - 1;
			while (n--)
			{
				*d-- = *s--;
			}
		}
		else
		{
			while (n--)
			{
				*d++ = *s++;
			}
		}
	}
	return (dest);
}
