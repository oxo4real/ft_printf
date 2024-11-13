/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_printer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghzal <aaghzal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 17:40:52 by marvin            #+#    #+#             */
/*   Updated: 2024/11/13 09:27:13 by aaghzal          ###   ########.fr       */
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
				int *p_r, char conversion, unsigned long long num)
{
	if (flag_data[ZERO_PADDING])
	{
		if (flag_data[IS_PRECISION])
			padding_printer(' ', flag_data[WIDTH] - flag_data[PRECISION], p_r);
		if ((flag_data[HASH] && num > 0) || conversion == 'p')
		{
			if (conversion == 'X')
				ft_putstr_fd("0X", 1);
			else
				ft_putstr_fd("0x", 1);
		}
		if (!flag_data[IS_PRECISION])
			padding_printer('0', flag_data[WIDTH] - flag_data[PRECISION], p_r);
	}
	else
	{
		padding_printer(' ', flag_data[WIDTH] - flag_data[PRECISION], p_r);
		if ((flag_data[HASH] && num > 0) || conversion == 'p')
		{
			if (conversion == 'X')
				ft_putstr_fd("0X", 1);
			else
				ft_putstr_fd("0x", 1);
		}
	}
}

void	hex_printer(unsigned long long n,
			int flag_data[FLAG_DATA_SIZE], int *p_rendu, char conversion)
{
	if ((n || !flag_data[IS_PRECISION]) && flag_data[PRECISION] < hex_len(n))
		flag_data[PRECISION] = hex_len(n);
	if (!flag_data[LEFT_JUSTIFIED])
	{
		if ((flag_data[HASH] && n > 0) || conversion == 'p')
		{
			flag_data[WIDTH] -= 2;
			(*p_rendu) += 2;
		}
		padding_handler(flag_data, p_rendu, conversion, n);
	}
	else if ((flag_data[HASH] && n > 0) || conversion == 'p')
	{
		if (conversion == 'X')
			ft_putstr_fd("0X", 1);
		else
			ft_putstr_fd("0x", 1);
		flag_data[WIDTH] -= 2;
		(*p_rendu) += 2;
	}
	padding_printer('0', flag_data[PRECISION] - hex_len(n), p_rendu);
	if (n || flag_data[PRECISION])
		x_printer(n, p_rendu, conversion);
	if (flag_data[LEFT_JUSTIFIED])
		padding_printer(' ', flag_data[WIDTH] - flag_data[PRECISION], p_rendu);
}
