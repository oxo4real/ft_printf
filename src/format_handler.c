/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 17:50:37 by marvin            #+#    #+#             */
/*   Updated: 2024/10/09 17:50:37 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	format_handler(const char *p_format, int *p_i, int *p_rendu, va_list args)
{
	int flag_data[FLAG_DATA_SIZE];
	int steps;

	steps = 0;
	ft_bzero(flag_data, sizeof(int) * FLAG_DATA_SIZE);
	(*p_i) += 1;
	steps += 1;
	while (ft_strchr("-0.*# +", p_format[(*p_i)]) || ft_isdigit(p_format[(*p_i)]))
	{
		if (!ft_isdigit(p_format[(*p_i)]))
			steps += 1;
		else
		 	steps += num_len(ft_atoi(&p_format[(*p_i)]));
		flag_handler(p_format, p_i, flag_data, args);
		(*p_i) += 1;
	}
	if (ft_strchr("cspdiuxX%", p_format[(*p_i)]))
		printer(p_format[(*p_i)++], p_rendu, flag_data, args);
	else
	{
		write(1, &p_format[(*p_i) - steps], steps);
		(*p_rendu) += steps;
	}
}
