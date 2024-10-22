/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uint_printer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghzal <aaghzal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 16:37:46 by marvin            #+#    #+#             */
/*   Updated: 2024/10/21 15:41:02 by aaghzal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void	u_printer(unsigned int un, int *p_rendu)
{
	char	c;

	c = (un % 10) + 48;
	if (un / 10 != 0)
		u_printer(un / 10, p_rendu);
	ft_putchar_fd(c, 1);
	(*p_rendu) += 1;
}

void	uint_printer(unsigned int un,
			int flag_data[FLAG_DATA_SIZE], int *p_rendu)
{
	if (flag_data[PRECISION] < num_len(un))
		flag_data[PRECISION] = num_len(un);
	if (!flag_data[LEFT_JUSTIFIED])
	{
		if (flag_data[ZERO_PADDING])
			padding_printer('0',
				flag_data[WIDTH] - flag_data[PRECISION], p_rendu);
		else
			padding_printer(' ',
				flag_data[WIDTH] - flag_data[PRECISION], p_rendu);
	}
	padding_printer('0', flag_data[PRECISION] - num_len(un), p_rendu);
	u_printer(un, p_rendu);
	if (flag_data[LEFT_JUSTIFIED])
		padding_printer(' ', flag_data[WIDTH] - flag_data[PRECISION], p_rendu);
}
