/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer_printer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 18:05:30 by marvin            #+#    #+#             */
/*   Updated: 2024/10/11 18:05:30 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	pointer_printer(unsigned long long ln, int flag_data[FLAG_DATA_SIZE], int *p_rendu)
{
	if (ln)
	{
		flag_data[HASH] = 1;
		hex_printer(ln, flag_data, p_rendu, 'p');
	}
	else
	{
		if (!flag_data[LEFT_JUSTIFIED])
			padding_printer(' ', flag_data[WIDTH] - 5, p_rendu);
		ft_putstr_fd("(nil)", 1);
		(*p_rendu) += 5;
		if (flag_data[LEFT_JUSTIFIED])
			padding_printer(' ', flag_data[WIDTH] - 5, p_rendu);
	}
}
