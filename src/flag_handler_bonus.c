/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_handler_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghzal <aaghzal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 19:16:32 by marvin            #+#    #+#             */
/*   Updated: 2024/11/13 11:43:43 by aaghzal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	flag_handler_bonus(const char *p_format, int *p_i,
			int flag_data[FLAG_DATA_SIZE])
{
	if (p_format[(*p_i)] == '#')
		flag_data[HASH] = 1;
	else if (p_format[(*p_i)] == '+')
		flag_data[PLUS] = 1;
	else if (p_format[(*p_i)] == ' ')
		flag_data[SPACE] = 1;
	else if (p_format[(*p_i)] == '-')
		flag_data[LEFT_JUSTIFIED] = 1;
	else if (p_format[(*p_i)] == '0')
		flag_data[ZERO_PADDING] = 1;
	else if (p_format[(*p_i)] == '.')
	{
		(*p_i) += 1;
		if (ft_isdigit(p_format[(*p_i)]))
			flag_data[PRECISION] = num_handler(&p_format[(*p_i)], p_i);
		else
			(*p_i) -= 1;
		flag_data[IS_PRECISION] = 1;
	}
}
