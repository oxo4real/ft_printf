/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_printer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghzal <aaghzal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 17:13:44 by marvin            #+#    #+#             */
/*   Updated: 2024/11/19 17:29:49 by aaghzal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void	s_printer(char *str, int *p_rendu, int width)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && i < width)
	{
		ft_putchar_fd(str[i], 1);
		i++;
		(*p_rendu) += 1;
	}
}

void	str_printer(char *s, int flag_data[FLAG_DATA_SIZE], int *p_rendu)
{
	if (!s)
		s = "(null)";
	if (!flag_data[IS_PRECISION] || flag_data[PRECISION] > (int)ft_strlen(s))
		flag_data[PRECISION] = ft_strlen(s);
	if (!flag_data[LEFT_JUSTIFIED])
		padding_printer(' ',
			flag_data[WIDTH] - flag_data[PRECISION], p_rendu);
	s_printer(s, p_rendu, flag_data[PRECISION]);
	if (flag_data[LEFT_JUSTIFIED])
		padding_printer(' ',
			flag_data[WIDTH] - flag_data[PRECISION], p_rendu);
}
