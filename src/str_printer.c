/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_printer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghzal <aaghzal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 17:13:44 by marvin            #+#    #+#             */
/*   Updated: 2024/10/22 11:46:51 by aaghzal          ###   ########.fr       */
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

void	str_printer(char *str, int flag_data[FLAG_DATA_SIZE], int *p_rendu)
{
	if (str)
	{
		if (!flag_data[IS_PRECISION])
			flag_data[PRECISION] = ft_strlen(str);
		if (!flag_data[LEFT_JUSTIFIED])
			padding_printer(' ',
				flag_data[WIDTH] - flag_data[PRECISION], p_rendu);
		s_printer(str, p_rendu, flag_data[PRECISION]);
		if (flag_data[LEFT_JUSTIFIED])
			padding_printer(' ',
				flag_data[WIDTH] - flag_data[PRECISION], p_rendu);
	}
	else
	{
		if (!flag_data[IS_PRECISION])
			flag_data[PRECISION] = 6;
		s_printer("(null)", p_rendu, flag_data[PRECISION]);
	}
}
