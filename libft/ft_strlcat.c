/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 11:40:30 by aaghzal           #+#    #+#             */
/*   Updated: 2024/08/08 21:44:08 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, char *src, size_t size)
{
	int		i;
	size_t	j;
	int		dest_len;

	dest_len = ft_strlen(dest);
	i = 0;
	if (size <= (size_t)dest_len)
		return (size + ft_strlen(src));
	if (size - (dest_len + 1))
	{
		while (dest[i] != 0)
		{
			i++;
		}
		j = 0;
		while (src[j] != 0 && j < size - (dest_len + 1))
		{
			dest[i] = src[j];
			j++;
			i++;
		}
		dest[i] = 0;
	}
	return (dest_len + ft_strlen(src));
}
