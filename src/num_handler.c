/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghzal <aaghzal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 11:25:06 by marvin            #+#    #+#             */
/*   Updated: 2024/11/12 14:35:14 by aaghzal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	zero_counter(const char *str)
{
	int	i;

	i = 0;
	while (str[i] == '0')
		i++;
	return (i);
}

int	num_handler(const char *str, int *p_i)
{
	int	rendu;
	int	zerowat;

	rendu = ft_atoi(str);
	zerowat = 0;
	if (rendu)
		zerowat = zero_counter(str);
	(*p_i) += num_len(rendu) - 1 + zerowat;
	return (rendu);
}
