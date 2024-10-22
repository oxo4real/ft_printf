/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghzal <aaghzal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 14:34:16 by marvin            #+#    #+#             */
/*   Updated: 2024/10/22 12:05:20 by aaghzal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void	percent_printer(int *p_rendu, int flag_data[FLAG_DATA_SIZE])
{
	if (!flag_data[LEFT_JUSTIFIED])
	{
		if (!flag_data[ZERO_PADDING])
			padding_printer(' ', flag_data[WIDTH] - 1, p_rendu);
		else
			padding_printer('0', flag_data[WIDTH] - 1, p_rendu);
	}
	ft_putchar_fd('%', 1);
	if (flag_data[LEFT_JUSTIFIED])
		padding_printer(' ', flag_data[WIDTH] - 1, p_rendu);
	(*p_rendu) += 1;
}

void	converter(char conversion, int *p_rendu,
			int flag_data[FLAG_DATA_SIZE], va_list args)
{
	if (conversion == 'c')
		char_printer(va_arg(args, int), flag_data, p_rendu);
	else if (conversion == 's')
		str_printer(va_arg(args, char *), flag_data, p_rendu);
	else if ((conversion == 'i' || conversion == 'd') && !flag_data[SHORT])
		int_printer(va_arg(args, int), flag_data, p_rendu);
	else if ((conversion == 'i' || conversion == 'd') && flag_data[SHORT])
		int_printer((short int)va_arg(args, int), flag_data, p_rendu);
	else if (conversion == 'u' && !flag_data[SHORT])
		uint_printer(va_arg(args, unsigned int), flag_data, p_rendu);
	else if (conversion == 'u' && flag_data[SHORT])
		uint_printer((unsigned short)va_arg(args, unsigned int),
			flag_data, p_rendu);
	else if ((conversion == 'x' || conversion == 'X') && !flag_data[SHORT])
		hex_printer((unsigned int)va_arg(args, unsigned int),
			flag_data, p_rendu, conversion);
	else if ((conversion == 'x' || conversion == 'X') && flag_data[SHORT])
		hex_printer((unsigned short)va_arg(args, unsigned int),
			flag_data, p_rendu, conversion);
	else if (conversion == 'p')
		pointer_printer(va_arg(args, unsigned long long), flag_data, p_rendu);
	else if (conversion == 'n')
		n_bonus(p_rendu, args, flag_data);
	else
		percent_printer(p_rendu, flag_data);
}
