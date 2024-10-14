/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 14:27:53 by marvin            #+#    #+#             */
/*   Updated: 2024/10/11 14:27:53 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	flag_handler(const char *p_format, int *p_i, int flag_data[FLAG_DATA_SIZE], va_list args)
{
	if (p_format[(*p_i)] == '-')
		flag_data[LEFT_JUSTIFIED] = 1;
	else if (p_format[(*p_i)] == '0' && flag_data[LEFT_JUSTIFIED] == 0)
		flag_data[ZERO_PADDING] = 1;
	else if (p_format[(*p_i)] == '*')
		flag_data[WIDTH] = va_arg(args, int); //to revise
	else if (ft_isdigit(p_format[(*p_i)]))
		flag_data[WIDTH] = num_handler(&p_format[(*p_i)], p_i);
	else if (p_format[(*p_i)] == '.')
	{
		(*p_i) += 1;
		if (p_format[(*p_i)] == '*')
			flag_data[PRECISION] = va_arg(args, int); //to revise
		else if (ft_isdigit(p_format[(*p_i)]))
			flag_data[PRECISION] = num_handler(&p_format[(*p_i)], p_i);
		else
		 	(*p_i) -= 1;
		flag_data[IS_PRECISION] = 1;
	}
}
