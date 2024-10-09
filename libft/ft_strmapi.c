/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 12:45:08 by marvin            #+#    #+#             */
/*   Updated: 2024/08/07 12:45:08 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	int				len;
	char			*rendu;

	if (s && f)
	{
		len = ft_strlen(s) + 1;
		rendu = (char *)malloc(sizeof(char) * len);
		if (!rendu)
			return (NULL);
		i = 0;
		while (s[i])
		{
			rendu[i] = f(i, s[i]);
			i++;
		}
		rendu[i] = 0;
		return (rendu);
	}
	return (NULL);
}
