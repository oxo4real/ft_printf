/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 18:51:40 by marvin            #+#    #+#             */
/*   Updated: 2024/08/08 18:51:40 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (src[i] != 0 && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = 0;
		i++;
	}
	return (dest);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*rendu;

	if (s)
	{
		if (start >= ft_strlen(s))
		{
			rendu = (char *)malloc(1);
			if (!rendu)
				return (NULL);
			rendu[0] = 0;
			return (rendu);
		}
		if (ft_strlen(s) - start < len)
			len = ft_strlen(s) - start;
		rendu = (char *)malloc(len + 1);
		if (!rendu)
			return (NULL);
		ft_strncpy(rendu, &s[start], len);
		rendu[len] = 0;
		return (rendu);
	}
	return (NULL);
}
