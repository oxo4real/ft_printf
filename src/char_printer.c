/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_printer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghzal <aaghzal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 17:07:58 by marvin            #+#    #+#             */
/*   Updated: 2024/10/21 15:22:02 by aaghzal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void	c_printer(char c, int *p_rendu)
{
	ft_putchar_fd(c, 1);
	(*p_rendu) += 1;
}

void	char_printer(char c, int flag_data[FLAG_DATA_SIZE], int *p_rendu)
{
	if (!flag_data[LEFT_JUSTIFIED])
		padding_printer(' ', flag_data[WIDTH] - 1, p_rendu);
	c_printer(c, p_rendu);
	if (flag_data[LEFT_JUSTIFIED])
		padding_printer(' ', flag_data[WIDTH] - 1, p_rendu);
}
