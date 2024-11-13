/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghzal <aaghzal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 17:50:37 by marvin            #+#    #+#             */
/*   Updated: 2024/11/13 13:54:48 by aaghzal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	format_handler(const char *p_format, int *p_i,
			int *p_rendu, va_list args)
{
	int	flag_data[FLAG_DATA_SIZE];

	ft_bzero(flag_data, sizeof(int) * FLAG_DATA_SIZE);
	while (ft_strchr("-0.# +", p_format[(*p_i)])
		|| ft_isdigit(p_format[(*p_i)]))
	{
		if (ft_strchr("-0.# +", p_format[(*p_i)]))
			flag_handler_bonus(p_format, p_i, flag_data);
		else if (ft_isdigit(p_format[(*p_i)]))
		{
			flag_data[WIDTH] = ft_atoi((&p_format[(*p_i)]));
			(*p_i) += num_len(ft_atoi((&p_format[(*p_i)])));
			continue ;
		}
		(*p_i) += 1;
	}
	if (ft_strchr("cspdiuxX%", p_format[(*p_i)]))
		converter(p_format[(*p_i)++], p_rendu, flag_data, args);
	else
		char_printer(p_format[(*p_i)++], flag_data, p_rendu);
}
