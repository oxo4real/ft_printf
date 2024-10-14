/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_handler_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 19:16:32 by marvin            #+#    #+#             */
/*   Updated: 2024/10/14 19:16:32 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	flag_handler_bonus(const char *p_format, int *p_i, int flag_data[FLAG_DATA_SIZE])
{
	if (p_format[(*p_i)] == '#')
		flag_data[HASH] = 1;
	else if (p_format[(*p_i)] == '+')
		flag_data[PLUS] = 1;
	else if (p_format[(*p_i)] == ' ')
		flag_data[SPACE] = 1;
	else if (p_format[(*p_i)] == 'h')
		flag_data[SHORT] = 1;
}
