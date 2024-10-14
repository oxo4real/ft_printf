/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_printer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 17:18:54 by marvin            #+#    #+#             */
/*   Updated: 2024/10/11 17:18:54 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void	i_printer(int num, int *p_rendu)
{
	char			c;
	unsigned int	nb;
	
	nb = (unsigned int) num;
	if (num < 0)
	{
		nb = ~0u - nb + 1;
		(*p_rendu) += 1;
	}
	c = (nb % 10) + 48;
	if (nb / 10 != 0)
		i_printer(nb / 10, p_rendu);
	ft_putchar_fd(c, 1);
	(*p_rendu) += 1;
}

static void	padding_handler(int num, int flag_data[FLAG_DATA_SIZE], int *p_rendu)
{
	int width;

	width = flag_data[WIDTH] - flag_data[PRECISION];
	if (flag_data[ZERO_PADDING])
	{
		if (num < 0)
			ft_putchar_fd('-', 1);
		else if (flag_data[PLUS] && num)
		{
			ft_putchar_fd('+', 1);
			(*p_rendu) += 1;
		}
		padding_printer('0', width, p_rendu);
	}
	else
	{
		padding_printer(' ', width, p_rendu);
		if (num < 0)
			ft_putchar_fd('-', 1);
		else if (flag_data[PLUS] && num)
		{
			ft_putchar_fd('+', 1);
			(*p_rendu) += 1;
		}
	}
}

void	int_printer(int num, int flag_data[FLAG_DATA_SIZE], int *p_rendu)
{
	if (flag_data[PLUS] || flag_data[SPACE] || num < 0)
		flag_data[WIDTH] -= 1;
	if (flag_data[SPACE] && num >= 0 && !flag_data[PLUS])
	{
		ft_putchar_fd(' ', 1);
		(*p_rendu) += 1;
	}
	if (flag_data[PRECISION] < num_len(num))
		flag_data[PRECISION] = num_len(num);
	if (!flag_data[LEFT_JUSTIFIED])
		padding_handler(num, flag_data, p_rendu);
	padding_printer('0', flag_data[PRECISION] - num_len(num), p_rendu);
	i_printer(num, p_rendu);
	if (flag_data[LEFT_JUSTIFIED])
		padding_printer(' ', flag_data[WIDTH] - flag_data[PRECISION], p_rendu);
}
