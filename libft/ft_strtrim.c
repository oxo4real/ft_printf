/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 11:56:17 by marvin            #+#    #+#             */
/*   Updated: 2024/08/08 11:56:17 by marvin           ###   ########.fr       */
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


static int	ft_inset(char const *set, char c)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if(set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
    char	*start;
    char	*end;
    char	*result;
    size_t	len;

    if (!s1)
        return (NULL);
    start = (char *)s1;
    end = start + ft_strlen(s1) - 1;
    while (start <= end && ft_inset(set, (*start)))
        start++;
    while (end >= start && ft_inset(set, (*end)))
        end--;
    len = end - start + 1;
    result = (char *)malloc(sizeof(char) * (len + 1));
    if (!result)
        return (NULL);
    ft_strncpy(result, start, len);
    result[len] = '\0';
    return (result);
}
