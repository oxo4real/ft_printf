/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_printer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghzal <aaghzal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 17:40:52 by marvin            #+#    #+#             */
/*   Updated: 2024/10/22 11:57:58 by aaghzal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void	x_printer(unsigned long long num, int *p_rendu, char conversion)
{
	char	c;
	char	*base;

	if (conversion == 'x' || conversion == 'p')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	c = base[num % 16];
	if (num / 16 != 0)
		x_printer(num / 16, p_rendu, conversion);
	ft_putchar_fd(c, 1);
	(*p_rendu) += 1;
}

static void	padding_handler(int flag_data[FLAG_DATA_SIZE],
				int *p_rendu, char conversion, unsigned long long num)
{
	int	width;

	width = flag_data[WIDTH] - flag_data[PRECISION];
	if (flag_data[ZERO_PADDING])
	{
		if ((flag_data[HASH] && num > 0) || conversion == 'p')
		{
			if (conversion == 'X')
				ft_putstr_fd("0X", 1);
			else
				ft_putstr_fd("0x", 1);
		}
		padding_printer('0', width, p_rendu);
	}
	else
	{
		padding_printer(' ', width, p_rendu);
		if ((flag_data[HASH] && num > 0) || conversion == 'p')
		{
			if (conversion == 'X')
				ft_putstr_fd("0X", 1);
			else
				ft_putstr_fd("0x", 1);
		}
	}
}

void	hex_printer(unsigned long long num,
			int flag_data[FLAG_DATA_SIZE], int *p_rendu, char conversion)
{
	if (flag_data[PRECISION] < hex_len(num))
		flag_data[PRECISION] = hex_len(num);
	if (!flag_data[LEFT_JUSTIFIED])
	{
		if ((flag_data[HASH] && num > 0) || conversion == 'p')
		{
			flag_data[WIDTH] -= 2;
			(*p_rendu) += 2;
		}
		padding_handler(flag_data, p_rendu, conversion, num);
	}
	else if ((flag_data[HASH] && num > 0) || conversion == 'p')
	{
		if (conversion == 'X')
			ft_putstr_fd("0X", 1);
		else
			ft_putstr_fd("0x", 1);
		flag_data[WIDTH] -= 2;
		(*p_rendu) += 2;
	}
	padding_printer('0', flag_data[PRECISION] - hex_len(num), p_rendu);
	x_printer(num, p_rendu, conversion);
	if (flag_data[LEFT_JUSTIFIED])
		padding_printer(' ', flag_data[WIDTH] - flag_data[PRECISION], p_rendu);
}
