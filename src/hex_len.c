/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_len.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghzal <aaghzal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 06:31:37 by marvin            #+#    #+#             */
/*   Updated: 2024/10/22 11:01:02 by aaghzal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	hex_len(unsigned long long num)
{
	int	count;

	count = 0;
	if (!num)
		return (1);
	while (num)
	{
		count += 1;
		num /= 16;
	}
	return (count);
}
