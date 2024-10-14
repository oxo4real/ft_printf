/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_len.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 06:31:37 by marvin            #+#    #+#             */
/*   Updated: 2024/10/12 06:31:37 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	hex_len(unsigned long long num)
{
	int	count;

	count = 0;
	while (num)
	{
		count += 1;
		num /= 16;
	}
	return (count);
}