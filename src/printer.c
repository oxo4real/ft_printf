/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 14:34:16 by marvin            #+#    #+#             */
/*   Updated: 2024/10/11 14:34:16 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	printer(char conversion, int *p_rendu, int flag_data[FLAG_DATA_SIZE], va_list args)
{
	if (conversion == 'c')
		char_printer(va_arg(args, int), flag_data, p_rendu);
	else if (conversion == 's')
		str_printer(va_arg(args, char *), flag_data, p_rendu);
	else if (conversion == 'i' || conversion == 'd')
		int_printer(va_arg(args, int), flag_data, p_rendu);
	else if (conversion == 'u')
		uint_printer(va_arg(args, unsigned int), flag_data, p_rendu);
	else if (conversion == 'x' || conversion == 'X')
		hex_printer(va_arg(args, unsigned int), flag_data, p_rendu, conversion);
	else if (conversion == 'p')
		pointer_printer(va_arg(args, long long), flag_data, p_rendu);
	else
	{
		ft_putchar_fd('%', 1);
		(*p_rendu) += 1;
	}
}
